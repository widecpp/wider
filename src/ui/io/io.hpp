#ifndef UI_IO_HPP
#define UI_IO_HPP

namespace wider::ui::io
{
    struct Data
    {
        struct
        {
            float x;
            float y;

            float deltaX;
            float deltaY;
        } mouse;
    };

    void begin(Data &data);
    void end(Data &data);
}

#endif // UI_IO_HPP