#include <iostream>
#include <string>
#include "MultiPoint.h"

using namespace std;

class Renderer
{
public:
	// Constructors
	Renderer();
	~Renderer();

	// Functions
	void render(std::vector<MultiPoint> g);
	MultiPoint* animationRender(MultiPoint g);
};

