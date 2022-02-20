#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <utility>
int main()
{
	using namespace Graph_lib;
	Simple_window win {{100,100},1000,800,"Simple_window"};
	int xmax = 800;
	int ymax = 800;
	int xgrid = 100;
	int ygrid = 100;
	Lines grid;
	for (int x=xgrid; x<=xmax; x+=xgrid)
		grid.add(Point{x,0},Point{x,ymax}); // vertical line
	for (int y = ygrid; y<=ymax; y+=ygrid)
		grid.add(Point{0,y},Point{xmax,y});	
	Vector_ref<Rectangle> vr;
	int valt = 0;
	int bruh = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vr.push_back(new Rectangle{Point{bruh*100,valt*100},100,100});
			bruh++;
			valt++;
			vr[vr.size()-1].set_fill_color(Color::red);
			win.attach(vr[vr.size()-1]);
		}
	}
	Image ii {Point{300,100},"badged.jpg"};
	Image ii1 {Point{300,500},"badged.jpg"};
	Image ii2 {Point{500,100},"badged.jpg"};
	win.attach(ii);
	win.attach(ii1);
	win.attach(ii2);
	win.attach(grid);
	int kep_meret100=100;
    Image ii3(Point(0,0),"badge.jpg");
    ii3.set_mask(Point(200,0),kep_meret100,kep_meret100);
    win.attach(ii3);
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		win.wait_for_button();
    		if (j < 7) ii3.move(100,0);
    		else ii3.move(-700,100);
    	}
    }

}