#include <iostream>
#include <string>

using namespace std;

void favWhileLoop() {
	double i = 2;
	while (true) {
		system("cls");
		cout << "How many loops already: " << i;
		i *= 800;
		i += (i < 0 ? 1 : i == 0 ? 1 : -1);
	}
}

void main2() {
	int y = 0;
	int x = 5 / y;
	for (int i = 1; i < 1000000; i *= 2) {
		if (i < 4) 
		{
			i += 3;
			continue;
		}
		cout << i << endl;
	}
	system("pause");
}

void doWhile() {
	int i = 0;
	do {
		// st00f
		i++;
	}
	while (i == 1);
}

void mosaicMania() {
	int i = 2;
	while (true) {
		cout << "How many loops already: " << i;
		i *= 2;
	}
}

int main() {
	//favWhileLoop();
	main2();
	for (int i = 0; i < 10; i++) {
		// st00f
	}
}