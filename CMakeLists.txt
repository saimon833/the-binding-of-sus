cmake_minimum_required(VERSION 3.0.0)
project(gaem VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(box2d REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${BOX2D_INCLUDE_DIRS})
add_executable(gaem src/main.cpp src/actor.cpp src/game.cpp src/texture_manager.cpp)
target_link_libraries(gaem ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

#target_link_libraries(gaem ${SDL2_LIBRARIES})