#include "io.hpp"
#include "../sdl/io.hpp"

void wider::ui::io::common::begin(Data &data)
{
	#ifdef WIDER_SDL2_SYSTEM
	wider::ui::io::sdl::begin(data);
	#endif
}

void wider::ui::io::common::end(Data &data)
{
	#ifdef WIDER_SDL2_SYSTEM
	wider::ui::io::sdl::end(data);
	#endif
}