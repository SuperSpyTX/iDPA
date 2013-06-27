#include <iostream>
#include <string>
#include <vector>
#include <xutility>

using namespace std;

class MultiPoint
{
public:
	// Constructors
	MultiPoint();
	MultiPoint(int* x, int* y, char character, int size, bool nstack);
	~MultiPoint();
	
	// Variables
	int *x, *y, size;
	char character;
	bool stack;

	// Functions
};

