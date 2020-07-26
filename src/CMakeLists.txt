set(WIDER_SOURCE
    ui/window/window.cpp
    main.cpp
)
add_executable(wider WIN32 ${WIDER_SOURCE})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT wider)

target_link_libraries(wider CONAN_PKG::sdl2)