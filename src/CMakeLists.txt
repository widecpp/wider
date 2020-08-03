# Source files
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
set(WIDER_SOURCE ${SRC_FILES})
#Executable
add_executable(wider WIN32 ${WIDER_SOURCE})
#Compile options
target_arch_compile_options(wider)
#Linking
target_link_libraries(wider PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(wider PRIVATE imgui::imgui)
