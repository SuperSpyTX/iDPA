#include <iostream>
#include <string>
#include <vector>
#include "Renderer.h"
//#include "MultiPoint.h"
//#include "AbstractPoint.h"
#include <time.h>

using namespace std;

AbstractPoint createAwesomeEffect();

int main() 
{
	srand(time(NULL));
	system("color b");
	Renderer renderer(20, 42);
	//renderer.showBorders = false;
	renderer.showDots = false;

	// Render bouncy letters.
	/*std::vector<GPoint> bouncymsgs;

	string msg;
	cout << "Please enter a message here: ";
	cin >> msg;
	int index = 0;
	int x = 0;
	for (string::iterator it = msg.begin() ; it < msg.end(); it++ , index++)
	{
	// *it
	if (x == 4)
	{
	x = 0;
	}
	GPoint g(1, x, *it);
	g.move = rand() % 6;
	bouncymsgs.push_back(g);
	x++;
	}
	renderer.renderBounce(bouncymsgs);*/

	// Render screen down effect.
	//renderer.renderScreenDown(5, 'X');

	// Render screen left (bool right?) effect.

	// Render scrolling letters

	renderer.renderScroll(createAwesomeEffect());

	system("pause");
}

AbstractPoint createAwesomeEffect()
{
	int nsx = 4, nsy = 40;
	int *x = new int[2];
	int *y = new int[2];

	x[0] = 0;
	y[0] = -2;
	x[1] = 1;
	y[1] = -2;
	AbstractPoint a(nsx,nsy,x,y,2,'W');
	return a;
}