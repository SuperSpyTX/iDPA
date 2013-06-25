#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int numberConv(int val) {
	switch (val) {
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
		break;
	default:
		return 0;
		break;
	}
}

int main() {
	// let's ask for some user input. (REF: 48-57 (numbers), 40-41 ( ( and ) ) 42-43 (* and +), 45 (-), 47 (/), 94 (^), 61 (=)
	string equation;
	cout << "Welcome to the Half Life 2 Episode 2 Calculator" << endl; // If I called it Half Life 3, it will never be finished
	cout << "Enter your equation here (EX: 2+3): " << endl;
	cin >> equation;
	
	// define variables.
	char empty = 0; // this is 0, it is used to extract the ascii char value by adding it.
	int x = 0, y = 0, res = -1, op = 0;

	// now let's figure out what the user wants to calculate.
	for(std::string::iterator it = equation.begin(); it != equation.end(); it++) { // found on stackoverflow
		//cout << *it+empty << ", ";
		
		// get the ascii value once again >.>
		int ascii = *it+empty;

		// Is it numbers?
		if (ascii >= 48 && ascii <= 57) {
			if (x == 0) {
				x = (x == 0 ? numberConv(*it) : x);
			} else if (y == 0) {
				y = (y == 0 ? numberConv(*it) : y);
			}
		// Is it an operation?
		} else if (ascii >= 42 && ascii <= 43 || /*check < 40 && check > 41 &&*/ ascii == 45 || ascii == 47 /*&& check != 94 && check != 61*/) {
			op = (op == 0 ? ascii : op);
		}

		if (x != 0 && y != 0 && op != 0) {
			break;
		}
	}

	// calculate!
	// TODO: do multiple calculations (requires vectors(?))

	switch(op) {
	case 42:
		res = x * y;
		break;
	case 43:
		res = x + y;
		break;
	case 45:
		res = x - y;
		break;
	case 47:
		res = x / y;
		break;
	}

	cout << "Your answer: " << res << endl;
	system("pause");
}