#include "Simple_window.h"
#include "Graph.h"
int main()
{
	using namespace Graph_lib;
	Simple_window win {{100,100},600,400,"My window"};
	Axis xa {Axis::x, Point{10,300}, 280, 10, "x axis"};
	xa.set_color(Color::green);
	
	Axis ya {Axis::y, Point{10,300}, 280, 10, "y axis"};
	ya.set_color(Color::blue);
	ya.label.set_color(Color::dark_blue);
	
	Function sine {cos,0,100,Point{20,150},1000,50,50};
	
	sine.set_color(Color::dark_blue);
	Polygon poly; 
	poly.add(Point{300,200}); 
	poly.add(Point{350,100});
	poly.add(Point{200,100});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	Rectangle r {Point{200,200}, 100, 50}; 
	win.attach(r);
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	
	poly_rect.add(Point{50,75});
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	Text t {Point{150,150}, "Hello, graphical world!"};
	
	t.set_font(Font::times_bold);
	t.set_color(Color::green);
	t.set_font_size(10);
	Image ii {Point{100,100},"badge.jpg"}; 
	Circle c {Point{100,200},20};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_green);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	win.attach(ii);
	win.attach(sine);
	win.attach(ya);
	win.attach(xa);
	win.attach(poly_rect);
	
	win.attach(t);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);

	win.wait_for_button();
}