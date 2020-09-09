set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/finders)

add_definitions (-D_GLIBCXX_USE_CXX11_ABI=1)
find_package(gtkmm)
find_package(glib)
#find_package(GTK2 REQUIRED gtkmm)
#find_package(efsw CONFIG REQUIRED)

find_path(BOOST_DLL_INCLUDE_DIRS "boost/dll.hpp")