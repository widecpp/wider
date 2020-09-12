#ifndef LAYOUT_FACTORY
#define LAYOUT_FACTORY

#include <memory>

namespace wider::ui::layout
{
    class Layout;

    class LayoutFactory
    {
    public:
        static std::shared_ptr<Layout> createMainLayout();
    };
}

#endif // LAYOUT_FACTORY
