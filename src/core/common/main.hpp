#ifndef MAIN_HPP
#define MAIN_HPP

namespace wider::core
{
    class WiderApp;

    int wider_main(int argc, char *argv[], void (*evCallback)(WiderApp &app));
}

#endif // MAIN_HPP