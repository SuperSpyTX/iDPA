#include "MultiPoint.h"

MultiPoint::MultiPoint()
{
	size = 1;
	x = new int[size];
	y = new int[size];
	x[0] = 4;
	y[0] = 8;
	character = '+';
	stack = false;
}

/*MultiPoint::MultiPoint(const MultiPoint &copy) {
	size = copy.size;
	x = copy.x;
	y = copy.y;
	character = copy.character;
}*/
MultiPoint::MultiPoint(int* nx, int* ny, char ncharacter, int nsize, bool nstack) 
{
	size = nsize;
	x = nx;
	y = ny;
	character = ncharacter;
	stack = nstack;
}



MultiPoint::~MultiPoint()
{
}
