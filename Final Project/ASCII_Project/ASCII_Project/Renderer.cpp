#include "Renderer.h"
#include <random>

// THIS IS A ABSTRACT BASE FOR ALL ITERATORS!
/*void iteratorBase()
{
system("cls");
for (int row = 0; row < rows; row++) {
char dot = '.';
bool borderRow = false;
if (row == 0 || row == (rows - 1)) {
borderRow = true;
}
for (int column = 0; column < columns; column++) {
bool lock = false;

if (borderRow || column == 0 || column == (columns - 1)) {
dot = (showBorders ? 42 : ' '); 
} else if (!lock) {
dot = (showDots ? '.' : ' ');
}

cout << dot;
if (column == (columns - 1)) {
cout << endl;
}
}
}
}*/

int getOpposite(int dir) 
{
	switch (dir) {
	case -2:
		return 2;
		break;
	case -1:
		return 1;
		break;
	case 0:
		return 0;
		break;
	case 1:
		return -1;
		break;
	case 2:
		return -2;
		break;
	}
}

int getOneDirection(int dir, bool y) 
{
	int nx = 0, ny = 0;
	switch (dir) { // TODO: Split to function
	case -2:
		nx = -1;
		ny = -1;
		break;
	case -1:
		nx = -1;
		ny = 1;
		break;
	case 0:
		nx = -1;
		ny = -1;
		break;
	case 1:
		nx = 1;
		ny = -1;
		break;
	case 2:
		nx = 1;
		ny = 1;
		break;
	case 3:
		nx = -1;
		ny = 0;
		break;
	case 4:
		nx = 1;
		ny = 0;
		break;
	case 5:
		nx = 0;
		ny = -1;
		break;
	case 6:
		nx = 0;
		ny = 1;
		break;
	}

	return (y ? ny : nx);
}


Renderer::Renderer()
{
}

Renderer::Renderer(int nrows, int ncolumns)
{
	rows = nrows;
	columns = ncolumns;
	showBorders = true;
	showDots = true;
}


Renderer::~Renderer()
{
}

void Renderer::blankRender()
{
	// This is a debug function.
	// 20x42 (really just 18x40)
	for (int row = 0; row < rows; row++) {
		char dot = '.';
		bool borderRow = false;
		if (row == 0 || row == (rows - 1)) {
			borderRow = true;
			dot = (showBorders ? 42 : ' ');
		}
		for (int column = 0; column < columns; column++) {
			// TODO: Array input for multi-points!
			if (row == 4 && column == (42 / 2) - 2) {
				dot = '+';
			} else if (row == 5 && column == (42 / 2) - 4) {
				dot = '+';
			} else if (row == 6 && column == (42 / 2) - 6) {
				dot = '+';
			} else if (borderRow || column == 0 || column == (columns - 1)) {
				dot = 42;
			} else {
				dot = (showDots ? '.' : ' ');
			}
			cout << dot;
			if (column == (columns - 1)) {
				cout << endl;
			}
		}
	}
}

void Renderer::render(std::vector<MultiPoint> g)
{
	// 20x42 (really just 18x40)
	for(std::vector<MultiPoint>::iterator it = g.begin(); it != g.end(); ++it) { // stackoverflow (HARDCODE SUCKS)
		system("cls");
		//cout << endl;
		MultiPoint pt = *it;
		for (int row = 0; row < rows; row++) {
			char dot = '.';
			bool borderRow = false;
			if (row == 0 || row == (rows - 1)) {
				borderRow = true;
				dot = (showBorders ? 42 : ' ');
			}
			for (int column = 0; column < columns; column++) {
				// TODO: Array input for multi-points!
				bool lock = false;
				for (int i = 0; i < pt.size; i++) {
					if (pt.x[i] == row && pt.y[i] == column) {
						lock = true;
						dot = pt.character;
					} else if (pt.x[i] == row && pt.y[i] == -1) {
						// this means render an entire row.
						lock = true;
						dot = pt.character;
					}
				}
				if (borderRow || column == 0 || column == (columns - 1)) {
					dot = (showBorders ? 42 : ' '); 
				} else if (!lock) {
					dot = (showDots ? '.' : ' ');
				}
				cout << dot;
				if (column == (columns - 1)) {
					cout << endl;
				}
			}
		}
		//Sleep(1);
	}
}

std::vector<MultiPoint> Renderer::createAnimation(MultiPoint g) 
{
	std::vector<MultiPoint> newg;
	for (int i = 0; i < g.size; i++) {
		char character = g.character;
		bool stack = false;
		MultiPoint ng(g.x[i], g.y[i], character, 1, stack);
		newg.push_back(ng);
	}

	return newg;
}

std::vector<MultiPoint> Renderer::createRandomAnimation() 
{
	std::vector<MultiPoint> newg;
	for (int i = 0; i < 100; i++) {
		char character = rand();
		bool stack = false;
		MultiPoint ng(rand() % 19, rand() % 41, character, 1, stack);
		newg.push_back(ng);
	}

	return newg;
}

void Renderer::renderBounce(std::vector<GPoint> gp) 
{
	// The most complicated piece of code I'm going to write.
	std::vector<GPoint> updates(gp);
	while(true) {
		int i = 0;
		int temp = 0;
		system("cls");
		//GPoint gps = *it;
		//cout << endl;

		// Calculate Logic!
		i = 0;
		for(std::vector<GPoint>::iterator it = updates.begin(); it != updates.end(); ++it) { // stackoverflow (HARDCODE SUCKS)
			GPoint gps = *it;
			if (gps.needCalc) {
				// Calculate Movement
				int dir = gps.move;
				int nx = getOneDirection(dir, false), ny = getOneDirection(dir, true);

				// COLLISION CHECK!
				bool glitchout = false, colidedWithObject = false;
				int cx = gps.x + nx, cy = gps.y + ny;
				// check for any collisions FIRST.
				int j = 0;
				for(std::vector<GPoint>::iterator itg = updates.begin(); itg != updates.end(); ++itg) {
					GPoint gp2 = *itg;
					if (gps.uqid == gp2.uqid) {
						continue;
					} else if (cx == gp2.x && cy == gp2.y) {
						bool colidedWithObject = true;

						// Check what direction the current object should go.
						dir = getOpposite(dir);
						gp2.move = getOpposite(gp2.move);
						updates[j] = gp2;
					}
					j++;
				}
				if (cx < 0 || cx > (rows - 1) || cy < 0 || cy > (columns - 1)) { // If the ball glitches out!
					dir = 0;
					gps.x = ((rows - 2) / 2);
					gps.y = ((columns - 2) / 2);
					glitchout = true;
				} else if (cx == (rows - 1) && cy == 1) { // If the ball hits the bottom left corner.
					dir = -1;
				} else if (cx == 1 && cy == (columns - 1)) { // If the ball hits the top right corner.
					dir = 1;
				} else if (cx == (rows - 1) && cy == (columns - 1)) { // If the ball hits the bottom right corner.
					dir = -2;
				} else if (cx == 1 && cy == 1) { // If the ball hits the top left corner.
					dir = 2;
				} else if (cy == 1 || cy == (columns - 1)) { // If the ball hits the left or right.
					if (cy == 1) {
						dir = (dir == 1) ? 2 : (dir == -2) ? -1 : -1;
					} else {
						dir = (dir == 2) ? 1 : (dir == -1) ? -2 : 1;
					}
				} else if (cx == 1 || cx == (rows - 1)) { // if the ball hits the top or bottom.
					if (cx == 1) {
						dir = (dir == -1) ? 2 : (dir == -2) ? 1 : (dir == 1) ? 1 : 2;
					} else {
						dir = (dir == 2) ? -1 : (dir == 1) ? -2 : 1;
					}
				}

				// update
				gps.move = dir;
				nx = getOneDirection(dir, false);
				ny = getOneDirection(dir, true);

				// MOVE!
				gps.x += nx;
				gps.y += ny;
				gps.needCalc = (glitchout ? true : false);

				if (glitchout) {
					gps.move = 1;
				}
				updates[i] = gps;
			}
			i++;
		}
		bool skipFrame = false;
		for (int row = 0; row < rows; row++) {
			char dot = '.';
			bool borderRow = false;
			if (row == 0 || row == (rows - 1)) {
				borderRow = true;
				dot = (showBorders ? 42 : ' ');
			}
			for (int column = 0; column < columns; column++) {
				// TODO: Array input for multi-points!
				bool lock = false;
				if (borderRow || column == 0 || column == (columns - 1)) {
					dot = (showBorders ? 42 : ' ');
					lock = true;
				} else if (!lock) {
					dot = (showDots ? '.' : ' ');
				}

				// Check coords and place objects.
				i = 0;
				for(std::vector<GPoint>::iterator it = updates.begin(); it != updates.end(); ++it) {
					GPoint gps = *it;
					if (!gps.needCalc && gps.x == row && gps.y == column) {
						dot = gps.character;
						gps.needCalc = true;
						updates[i] = gps;
					}
					i++;
				}

				cout << dot;
				if (column == (columns - 1)) {
					cout << endl;
				}
			}
		}
	}
}


void Renderer::renderScroll(AbstractPoint ap)
{
	std::vector<AbstractPoint> aps(1, ap);
	int charleft = 0;
	AbstractPoint sel;
	bool skipNow = false;
	bool killWhile = false;
	while(true)
	{
		if (killWhile)
		{
			break;
		}
		std::vector<MultiPoint> gg;
		bool set = false;
		system("cls");
		for (int row = 0; row < rows; row++) {
			char dot = '.';
			bool borderRow = false;
			if (row == 0 || row == (rows - 1)) {
				borderRow = true;
			}
			for (int column = 0; column < columns; column++) {
				bool lock = false;

				if (borderRow || column == 0 || column == (columns - 1)) {
					dot = (showBorders ? 42 : ' '); 
				} else if (!lock) {
					dot = (showDots ? '.' : ' ');
				}

				// DRAW!
				int curriter = 0;
				if (!lock && !skipNow) {
					for (std::vector<AbstractPoint>::iterator it = aps.begin(); it != aps.end(); ++it)
					{
						if (charleft == curriter)
						{
							skipNow = true;
							sel = *it;
							charleft++;
						}
						curriter++;
					}
				}

				if (!lock && skipNow && !set && sel.startX == row && sel.startY == column) {
					// ABSTRACT POINT SYSTEM FTW.
					// Draws new points based on the current position.
					set = true;
					dot = sel.character;
					for (int i = 0; i < sel.size; i++) {
						// MultiPoint ng(sel.x[i], sel.y[i], sel.character, 1, false);
						int nx = row + sel.x[i], ny = column + sel.y[i];

						// If out of bounds, do not render.
						/*if (nx < 0 || nx > (rows - 1) || ny < 0 || ny > (columns - 1)) {
							continue;
						}*/
						if (sel.y[i] < 0) {
							int a = 0;
						}
						MultiPoint ng(nx, ny, sel.character, 1, false);
						gg.push_back(ng);
					}
					sel.startY--;
					if (sel.startY < 0) {
						//killWhile = true;
						sel.startY = (columns - 1);
					}
					aps[charleft - 1] = sel;
				}

				if (!lock) {
					for (std::vector<MultiPoint>::iterator ig = gg.begin(); ig != gg.end(); ++ig)
					{
						MultiPoint mp = *ig;
						if (mp.y[0] < 0) {
							int a = 0;
						}
						if (mp.x[0] == row && mp.y[0] == column)
						{
							dot = mp.character;
						}
					}
				}

				cout << dot;
				if (column == (columns - 1)) {
					cout << endl;
				}
			}
		}
	}
}

void Renderer::renderScreenDown(int objects, char character) 
{
	std::vector<MultiPoint> newg;
	int objscreated = 0;
	while (true) {
		system("cls");
		// Create
		if (objscreated < objects) {
			MultiPoint nobj(1, character, 1, false);
			newg.push_back(nobj);
			objscreated++;
		}

		// Map
		for (int row = 0; row < rows; row++) {
			char dot = '.';
			bool borderRow = false;
			if (row == 0 || row == (rows - 1)) {
				borderRow = true;
			}
			for (int column = 0; column < columns; column++) {
				bool lock = false;

				if (borderRow || column == 0 || column == (columns - 1)) {
					dot = (showBorders ? 42 : ' ');
					lock = true;
				} else if (!lock) {
					dot = (showDots ? '.' : ' ');
				}

				for (std::vector<MultiPoint>::iterator it = newg.begin(); it != newg.end(); ++it)
				{
					MultiPoint map = *it;
					if (!lock && row == map.row) {
						dot = character;
					}
				}

				cout << dot;
				if (column == (columns - 1)) {
					cout << endl;
				}
			}
		}

		// Update
		int i = 0;
		for (std::vector<MultiPoint>::iterator it = newg.begin(); it != newg.end(); ++it)
		{
			MultiPoint upd = *it;
			upd.row++;
			if (upd.row == (rows - 1)) {
				upd.row = -1;
				newg[i] = upd;
			} else {
				newg[i] = upd;
			}
			i++;
		}
	}

}

void Renderer::renderScreenLeft(int objects, char character, bool right)
{
	std::vector<MultiPoint> newg;
	int objscreated = 0;
	while (true) {
		system("cls");
		// Create
		if (objscreated < objects) {
			MultiPoint nobj(-1, (columns - 2), character, 1, false);
			newg.push_back(nobj);
			objscreated++;
		}

		// Map
		for (int row = 0; row < rows; row++) {
			char dot = '.';
			bool borderRow = false;
			if (row == 0 || row == (rows - 1)) {
				borderRow = true;
			}
			for (int column = 0; column < columns; column++) {
				bool lock = false;

				if (borderRow || column == 0 || column == (columns - 1)) {
					dot = (showBorders ? 42 : ' ');
					lock = true;
				} else if (!lock) {
					dot = (showDots ? '.' : ' ');
				}

				for (std::vector<MultiPoint>::iterator it = newg.begin(); it != newg.end(); ++it)
				{
					MultiPoint map = *it;
					if (!lock && column == map.y[0]) {
						dot = character;
					}
				}

				cout << dot;
				if (column == (columns - 1)) {
					cout << endl;
				}
			}
		}

		// Update
		int i = 0;
		for (std::vector<MultiPoint>::iterator it = newg.begin(); it != newg.end(); ++it)
		{
			MultiPoint upd = *it;
			upd.y[0]--;
			if (upd.y[0] == 1) {
				upd.y[0] = (columns - 1);
				newg[i] = upd;
			} else {
				newg[i] = upd;
			}
			i++;
		}
	}

}