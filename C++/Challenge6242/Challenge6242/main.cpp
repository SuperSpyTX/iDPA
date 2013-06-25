#include <iostream>
#include <string>

using namespace std;

int multi(int a, int b) {
	return a + a * b + (b / 2);
}

int main() {
	// define variables.
	int a = 0;
	int b = 1;
	double c = 0;
	double d = 0;
	char e = 'a';
	char f = 'c';
	string g = "";
	string h = "";

	// logical operations to confuse instructors.
	for (int i = 0; i < 2; i++) {
		a = multi(a,b);
		b = multi(a,b);
		c = (int)multi(a,b);
		d = (int)multi(c,b);
		d += multi(c+d, a+b);
		d += multi(d, (int)e+f);
	}

	char init[] = {87, 105, 110, 100, 111, 119, 115, 0}; // secret message (hehehehehe)
	string str(init);

	cout << str << " " << d << "\n\n\n" << "How??!?!?!?..\n"; // Output secret message and number.
	system("pause");
	return 0;
}


// scroll down after.

void build() {
	// This function is for reference on how init[] was built
	string win = "Windows"; // Secret Message!
	char empty = 0; // this is the trick to get the original value
	for(std::string::iterator it = win.begin(); it != win.end(); it++) { // found on stackoverflow
		cout << *it+empty << ", "; // spit out a series of numbers for the init[]
	}
	cout << "0"; // null terminator for array.
}