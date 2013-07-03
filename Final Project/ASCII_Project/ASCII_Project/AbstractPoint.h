#pragma once
class AbstractPoint
{
public:
	// Fields
	int startX, startY, *x, *y, size;
	char character;

	// Constructor
	AbstractPoint();
	AbstractPoint(int nstartX, int nstartY, int* nx, int* ny, int nsize, char ncharacter);
	~AbstractPoint();
};

