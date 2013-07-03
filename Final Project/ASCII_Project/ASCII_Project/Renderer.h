#include <iostream>
#include <string>
#include "GPoint.h"
#include "MultiPoint.h"
#include "AbstractPoint.h"

using namespace std;

class Renderer
{
public:
	// Fields
	int rows, columns;
	bool showBorders, showDots;

	// Constructors
	Renderer();
	Renderer(int rows, int columns);
	~Renderer();

	// Functions
	void render(std::vector<MultiPoint> g);
	void blankRender();
	void renderText(std::vector<string> text, int startX, int startY);
	void renderBounce(std::vector<GPoint> gp);
	void renderScroll(AbstractPoint ap);
	void renderScreenDown(int objects, char character);
	void renderScreenLeft(int objects, char character, bool right);
	std::vector<MultiPoint> createAnimation(MultiPoint g);
	std::vector<MultiPoint> createRandomAnimation();
};

