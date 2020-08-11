#ifndef UI_IO_DATA_HPP
#define UI_IO_DATA_HPP

namespace wider::ui::io
{
    struct Data
    {
        struct
        {
            int x;
            int y;

            bool left;
            bool right;
            bool middle;
        } mouse;
    };
}

#endif // UI_IO_DATA_HPP