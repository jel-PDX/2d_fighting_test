#include "collision.h"

#include <cmath>

#include "entity.h"

sf::Vector2<float> Collision::nudge() {
  float x_nudge{}, y_nudge{};

  if (c_col_dir == X_COL) {
    Entity** e1;
    Entity** e2;

    if (c_e1->getVel().x != 0) {
      e1 = &c_e1;
      e2 = &c_e2;
    } else {
      e1 = &c_e2;
      e2 = &c_e1;
    }

    float p1{(*e1)->getBounds().left};
    float p2{(*e2)->getBounds().left};
    float v1{(*e1)->getVel().x};
    float v2{(*e2)->getVel().x};
    float w{}, x1{}, x2{};

    if (p1 < p2) {
      w = (*e1)->getBounds().width;
      x1 = p1 + w + v1;
      x2 = p2 + v2;
    } else if (p1 > p2) {
      w = (*e2)->getBounds().width;
      x1 = p1 + v1;
      x2 = p2 + w + v2;
    }

    x_nudge = std::abs(x1 - x2);
  }

  else if (c_col_dir == Y_COL) {
    Entity** e1;
    Entity** e2;

    if (c_e1->getVel().y != 0) {
      e1 = &c_e1;
      e2 = &c_e2;
    } else {
      e1 = &c_e2;
      e2 = &c_e1;
    }

    float p1{(*e1)->getBounds().top};
    float p2{(*e2)->getBounds().top};
    float v1{(*e1)->getVel().y};
    float v2{(*e2)->getVel().y};
    float h{}, y1{}, y2{};

    if (p1 < p2) {
      h = (*e1)->getBounds().height;
      y1 = p1 + h + v1;
      y2 = p2 + v2;
    } else if (p1 > p2) {
      h = (*e2)->getBounds().height;
      y1 = p1 + v1;
      y2 = p2 + h + v2;
    }

    y_nudge = std::abs(y1 - y2);
  }

  return {x_nudge, y_nudge};
}

Collision::Collision() = default;

Collision::Collision(Entity* e1, Entity* e2, ColDir col_dir,
                     unordered_map<size_t, sf::Vector2<float>>* world_nudges)
    : c_e1{e1}, c_e2{e2}, c_col_dir{col_dir}, c_world_nudges{world_nudges} {}

void Collision::resolve() {
  // compare weights of entities
  //
  // if different, greater weight pushes the lesser weight, and assigns greater
  // weight to other entity
  //
  // if equal, negate all movement by both entities

  Entity::Weight e1_collision_weight;
  Entity::Weight e2_collision_weight;

  if (c_col_dir == X_COL) {
    e1_collision_weight = c_e1->getWeightX();
    e2_collision_weight = c_e2->getWeightX();
  } else if (c_col_dir == Y_COL) {
    e1_collision_weight = c_e1->getWeightY();
    e2_collision_weight = c_e2->getWeightY();
  }

  if (e1_collision_weight != e2_collision_weight)
    resolveImbalance(e1_collision_weight, e2_collision_weight);
  else
    resolveBalance(e1_collision_weight, e2_collision_weight);
}

void Collision::resolveImbalance(Entity::Weight w1, Entity::Weight w2) {
  Entity** e1;  // entity of greater weight
  Entity** e2;  // entity of lesser weight
  sf::Vector2<float> n{nudge()};
  float v1{};
  float v2{};

  if (w1 > w2) {
    e1 = &c_e1;
    e2 = &c_e2;
  } else {
    e1 = &c_e2;
    e2 = &c_e1;
  }

  if (c_col_dir == X_COL) {
    v1 = (*e1)->getVel().x;
    v2 = (*e2)->getVel().x;
    if (v2 < 0) {
      n.x *= -1;
    } else if (v2 == 0) {
      if (v1 > 0) n.x *= -1;
    }
    (*e2)->setVel(v2 - n.x, (*e2)->getVel().y);
    std::size_t e2_hash{(*e2)->getHash()};
    float old_nudge_x{(*c_world_nudges)[e2_hash].x};
    float new_nudge_x{old_nudge_x + n.x};
    (*c_world_nudges)[e2_hash].x = new_nudge_x;
    (*e2)->setWeightX((*e1)->getWeightX());
  } else if (c_col_dir == Y_COL) {
    v1 = (*e1)->getVel().y;
    v2 = (*e2)->getVel().y;
    if (v2 < 0) {
      n.y *= -1;
    } else if (v2 == 0) {
      if (v1 > 0) n.y *= -1;
    }
    (*e2)->setVel((*e2)->getVel().x, v2 - n.y);
    std::size_t e2_hash{(*e2)->getHash()};
    float old_nudge_y{(*c_world_nudges)[e2_hash].y};
    float new_nudge_y{old_nudge_y + n.y};
    (*c_world_nudges)[e2_hash].y = new_nudge_y;
    (*e2)->setWeightY((*e1)->getWeightY());
  }
}

void Collision::resolveBalance(Entity::Weight w1, Entity::Weight w2) {
  if (c_col_dir == X_COL) {
    c_e1->setVel(0, c_e1->getVel().y);
    c_e2->setVel(0, c_e2->getVel().y);
  } else if (c_col_dir == Y_COL) {
    c_e1->setVel(c_e1->getVel().x, 0);
    c_e2->setVel(c_e2->getVel().x, 0);
  }
}

std::size_t Collision::getHash() {
  HashFunction hash_function;
  return hash_function(*this);
}
