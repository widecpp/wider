cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)

project(wider CXX)

# Temporary, maybe configure with option by cmake?
add_definitions(-DWIDER_SDL2_SYSTEM)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/arch.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/cmake-cfg/thirdparty.cmake)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT wider)