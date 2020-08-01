cmake_minimum_required(VERSION 3.5)

project(wider CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/cmake-cfg/thirdparty.cmake)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT wider)