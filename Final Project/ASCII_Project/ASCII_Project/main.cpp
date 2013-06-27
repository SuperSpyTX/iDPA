#include <iostream>
#include <string>
#include "Renderer.h"
//#include "MultiPoint.h"

using namespace std;

int main() {
	Renderer renderer;
	MultiPoint mpoint;
	renderer.render(mpoint);

	system("pause");
}