#ifndef CONFIG_SYSTEM_PROVIDER_HPP
#define CONFIG_SYSTEM_PROVIDER_HPP

#include "data/data.hpp"

namespace wider::config::system
{
    class SystemConfigProvider
    {
    public:
    private:
        data::Data load();
        void save(const data::Data &data);
    };
}

#endif // CONFIG_SYSTEM_PROVIDER_HPP