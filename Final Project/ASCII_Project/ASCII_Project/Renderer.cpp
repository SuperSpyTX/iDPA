#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::render(std::vector<MultiPoint> g)
{
	// 20x42 (really just 18x40)
	int rows = 20;
	int width = 42;
	for (std::vector<MultiPoint>::iterator it = g.begin(); it != g.end(); ++it) { // stackoverflow
		system("cls");
		MultiPoint pt = *it;
		for (int row = 0; row < rows; row++) {
			char dot = '.';
			bool borderRow = false;
			if (row == 0 || row == (rows - 1)) {
				borderRow = true;
				dot = 42;
			}
			for (int column = 0; column < width; column++) {
				// TODO: Array input for multi-points!
				bool lock = false;
				for (int i = 0; i < pt.size; i++) {
					if (pt.x[i] == row && pt.y[i] == column) {
						lock = true;
						dot = pt.character;
					}
				}
				if (borderRow || column == 0 || column == (width - 1)) {
					dot = 42;
				} else if (!lock) {
					dot = '.';
				}
				cout << dot;
				if (column == (width - 1)) {
					cout << endl;
				}
			}
		}
	}
}

MultiPoint* Renderer::animationRender(MultiPoint g) 
{
	std::vector<MultiPoint> newg(g.size);
	std::vector<MultiPoint>::iterator it;
	it = newg.begin();
	for (int i = 0; i < g.size; i++) {
		int nx[1] = { g.x[i] }, ny[1] = { g.y[i] }, ;
	}
}