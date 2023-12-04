cmake_minimum_required(VERSION 3.16)

project(2d_fighting_test)

include (FetchContent)

# SFML
find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

# Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)

# Custom Libs and Headers
add_library(entity src/entity.cpp)

add_library(player src/player.cpp)

add_library(static_object src/static_object.cpp)

add_library(dynamic_object src/dynamic_object.cpp)

add_library(spatial_hash_grid src/spatial_hash_grid.cpp)

add_library(collision src/collision.cpp)

add_library(collisions_util src/collisions_util.cpp)

add_library(handle_global_collisions src/handle_global_collisions.cpp)

add_library(game_util src/game_util.cpp)

target_include_directories(entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(static_object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(dynamic_object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(spatial_hash_grid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(collisions_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(handle_global_collisions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(game_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Testing Executable
add_executable(tests test/test.cpp)

target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_link_libraries(tests PUBLIC spatial_hash_grid game_util handle_global_collisions collision collisions_util entity player static_object dynamic_object sfml-graphics sfml-window sfml-audio sfml-system PRIVATE Catch2::Catch2WithMain)

# Program Executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_link_libraries(${PROJECT_NAME} spatial_hash_grid game_util handle_global_collisions collision collisions_util entity player static_object dynamic_object sfml-graphics sfml-window sfml-audio sfml-system)
