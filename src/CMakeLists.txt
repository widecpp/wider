set(WIDER_SOURCE
    ui/window/window.cpp
    ui/window/sdl/window.cpp
    main.cpp
)
add_executable(wider WIN32 ${WIDER_SOURCE})

target_link_libraries(wider PRIVATE SDL2::SDL2 SDL2::SDL2main)