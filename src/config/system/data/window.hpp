#ifndef CONFIG_SYSTEM_DATA_WINDOW_HPP
#define CONFIG_SYSTEM_DATA_WINDOW_HPP

#include <optional>

namespace wider::config::system::data
{
    struct WindowData
    {
        std::optional<int> x, y;
        std::optional<int> width, height;
    };
};

#endif // CONFIG_SYSTEM_DATA_WINDOW_HPP