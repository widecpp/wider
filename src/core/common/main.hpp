#ifndef MAIN_HPP
#define MAIN_HPP

#include <functional>

namespace wider::core
{
    class WiderApp;

    int wider_main_own_cycle(int argc, char *argv[], std::function<void(WiderApp &app)> evCallback);
    int wider_main_out_cycle(int argc, char *argv[], std::function<int(WiderApp &app)> runCallback);
}

#endif // MAIN_HPP