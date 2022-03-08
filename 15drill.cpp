#include "Simple_window.h"
#include "Graph.h"
using namespace std;
struct Person
{
	string name;
	int age;


};
double one(double x) {return 1;}
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x/2); }
int main()
{
	using namespace Graph_lib;
	int xmax = 600;
	int ymax = 600;
	int slmin = -10;
	int slmax = 11;
	int sllength = 400;
	int x_cross = 300;
    	int y_cross = 300;
    	int x_scale = 20, y_scale = 20;
    	int xlength = 400, ylength = 400;
    	Point crossp {x_cross, y_cross};
	Simple_window win {Point{100,100}, xmax, ymax, "Function Graphs"};
	Axis x {Axis::x, Point{100, y_cross}, xlength,x_scale, "1==20 pixels"};
	Axis y {Axis::y, Point{x_cross, ylength+100}, ylength, y_scale};
	x.set_color(Color::dark_red);
	y.set_color(Color::dark_red);
	//Function sl (one, slmin, slmax, crossp, sllength);
	Function sl (one, slmin, slmax, crossp, sllength, x_scale, y_scale);
	Function slp(slope, slmin, slmax, crossp, sllength, x_scale, y_scale);
	Function sqre(square, slmin, slmax, crossp, sllength, x_scale, y_scale);
	Function cosine(cos,slmin,slmax,crossp,sllength,x_scale,y_scale);
	Function slp_cos(sloping_cos,slmin,slmax,crossp,sllength,x_scale,y_scale);
	Text label (Point(x_cross-200,y_cross+80),"x/2");
	cosine.set_color(Color::cyan);
	win.attach(label);
	win.attach(x);
	win.attach(y);
	win.attach(sl);
	win.attach(slp);
	win.attach(sqre);
	win.attach(cosine);
	win.attach(slp_cos);
	win.wait_for_button();

}
