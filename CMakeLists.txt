cmake_minimum_required(VERSION 3.6)
project(node_one)

set(CMAKE_CXX_STANDARD 11)

find_library(UAVCAN_LIB uavcan REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++11")

include_directories(libuavcan/libuavcan/include)

set(SOURCE_FILES node.cpp platform_stm32.cpp)
add_executable(node_one ${SOURCE_FILES})


target_link_libraries(node_one ${UAVCAN_LIB} rt)