cmake_minimum_required(VERSION 3.16)

project(2d_fighting_test)

# SFML
find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

# Custom Libs and Headers
add_library(entity src/entity.cpp)

add_library(player src/player.cpp)

add_library(static_object src/static_object.cpp)

add_library(dynamic_object src/dynamic_object.cpp)

add_library(spatial_hash_grid src/spatial_hash_grid.cpp)

add_library(collision src/collision.cpp)

add_library(collisions_util src/collisions_util.cpp)

add_library(scene src/scene.cpp)

add_library(ft src/ft.cpp)

target_include_directories(entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(static_object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(dynamic_object PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(spatial_hash_grid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(collisions_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(scene PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_include_directories(ft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Program Executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

target_link_libraries(${PROJECT_NAME} ft scene spatial_hash_grid collision collisions_util entity player static_object dynamic_object sfml-graphics sfml-window sfml-audio sfml-system)
