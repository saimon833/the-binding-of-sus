##LINUX
cmake_minimum_required(VERSION 3.0.0)
#set(CMAKE_C_COMPILER "/usr/bin/gcc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")
project(gaem VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
file(GLOB SRC
    "src/*.cpp"
)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)
find_package(box2d REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${BOX2D_INCLUDE_DIRS})
add_executable(gaem ${SRC})
target_link_libraries(gaem box2d ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY})
