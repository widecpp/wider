# Source files
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
set(WIDER_SOURCE ${SRC_FILES})
#Executable
add_module_executable(wider ${WIDER_SOURCE})
#Compiler dirs
target_include_directories(wider PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(wider PRIVATE ${BOOST_DLL_INCLUDE_DIRS})
#Compile options
target_arch_compile_options(wider)
#Linking

#