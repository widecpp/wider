#ifndef LAYOUT
#define LAYOUT

#include <memory>

namespace wider::ui::layout
{
    class Layout :
        public std::enable_shared_from_this<Layout>
    {
    public:
        virtual ~Layout() = default;
    };
}

#endif // LAYOUT
