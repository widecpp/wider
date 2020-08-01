#ifndef APP_HPP
#define APP_HPP

namespace wider::core
{
    class WiderApp
    {
    public:
        WiderApp(int argc, char **argv);

        bool quitRequested();
    public: // events
        // void onSomething();
        void onQuitRequested();
    private:
        struct {
            int argc;
            char **argv;
        } const args_;
        bool quitRequested_ = false;
    };
}

#endif // APP_HPP