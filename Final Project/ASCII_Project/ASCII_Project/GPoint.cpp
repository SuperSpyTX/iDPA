#include "GPoint.h"
#include <random>

GPoint::GPoint()
{
}

GPoint::GPoint(int nx, int ny, char ncharacter) 
{
	x = nx;
	y = ny;
	character = ncharacter;
	move = (rand() % 4);
	needCalc = true;
	uqid = rand() % 2000;
}

GPoint::~GPoint()
{
}
