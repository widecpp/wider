set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/finders)

find_package(gtkmm)
#find_package(GTK2 REQUIRED gtkmm)
#find_package(efsw CONFIG REQUIRED)

find_path(BOOST_DLL_INCLUDE_DIRS "boost/dll.hpp")