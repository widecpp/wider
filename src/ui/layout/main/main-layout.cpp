#include "main-layout.hpp"
using namespace wider::ui::layout;

bool MainLayout::on_draw(Cairo::RefPtr<Cairo::Context> const & cr)
{
	cr->set_line_width(3);

    cr->move_to( 11, 11);
    cr->line_to(111,111);
    cr->stroke();
    /*cr->set_source_rgb(1.,.5,.0);
    cr->set_line_width(3);

    cr->move_to( 11, 11);
    cr->line_to(111,111);
    cr->stroke();

    return true;*/
	return true;
}