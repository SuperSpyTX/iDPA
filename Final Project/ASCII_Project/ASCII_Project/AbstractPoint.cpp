#include "AbstractPoint.h"


AbstractPoint::AbstractPoint()
{
}

AbstractPoint::AbstractPoint(int nstartX, int nstartY, int* nx, int* ny, int nsize, char ncharacter)
{
	startX = nstartX;
	startY = nstartY;
	x = nx;
	y = ny;
	size = nsize;
	character = ncharacter;
}


AbstractPoint::~AbstractPoint()
{
}
