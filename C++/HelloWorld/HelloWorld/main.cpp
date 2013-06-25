/*
I like pie.
*/
#include <cmath>
#include <string>
#include <iostream>

using namespace std; // Standard namespace.

int add(int a, int b) {
	return a + b;
}

/* herp derp
int main2() {
	char a = 'a';
	char b = 'b';
	char c = a << 4;
	cout << c << endl;
	cout << a + b << endl;
	return 0;
}*/

int main() {
	system("color 4f"); // Batch command "color 4f", makes red screen.
	cout << "Hello Kitty!\n\n" << endl << "hai" << endl; // Echos message.
	printf("What am I writing..\n"); // Another way to print out hello world (printf).
	//system("pause"); // Batch pause. "Press any key to continue..."
	int a = add(1,2);
	cout << a << endl;
	system("pause");
	return 0; // Exit code.  -1 = error 0 = normal.
}