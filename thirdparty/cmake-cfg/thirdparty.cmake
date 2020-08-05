set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

find_package(OpenGL CONFIG REQUIRED)

find_path(BOOST_DLL_INCLUDE_DIRS "boost/dll.hpp")
