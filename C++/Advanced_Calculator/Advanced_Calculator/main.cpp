#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

double numberConv(int asciiCode, char arr[], int currPos) {
	// Unfortunately our way of getting the numbers for our equation only gets one digit.
	// This fixes that by looking ahead for numbers (via ascii numbers)
	// TODO: Find a better way of getting multi digits (REGEX)
	
	// def vars
	string fullnum;
	fullnum = char(asciiCode);
	int ti = currPos + 1;

	// do magic
	while ((arr[ti]+0) >= 48 && (arr[ti]+0) <=57 || (arr[ti]+0) == 46) {
		fullnum += arr[ti];
		ti++;
	}
	return atof(fullnum.c_str()); // found on cplusplus (helpful)
}
	/* This is for reference (ascii table for operations)
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
	*/

int main() {
	// let's ask for some user input. (REF: 48-57 (numbers), 40-41 ( ( and ) ) 42-43 (* and +), 45 (-), 46(.), 47 (/), 94 (^), 61 (=),
	string equation;
	cout << "Welcome to the Half Life 2 Episode 2 Calculator" << endl; // If I called it Half Life 3, it would never get finished <--- lol
	cout << "Enter your entire equation here (EX: 2+3): " << endl;
	cin >> equation;
	
	// define variables.
	char strs[500], empty = 0; // this is 0, it is used to extract the ascii char value by adding it.
	double x = 0, y[200];
	int opct = 0, ct = 0, op[200], fill = 0;

	// now let's figure out what the user wants to calculate.
	for(std::string::iterator it = equation.begin(); it != equation.end(); it++) { // found on stackoverflow
		strs[fill] = *it;
		fill++;
	}

	strs[fill+1] = '\0';

	for(int i = 0; i < fill; i++) { // found on stackoverflow
		//cout << *it+empty << ", ";
		char ent = strs[i];

		// get the ascii value once again >.>
		int ascii = ent+empty;

		// Is it numbers?
		if (ascii >= 48 && ascii <= 57) {
				string fullnum;
				fullnum = char(ascii);
				int ti = i + 1;
				
				// Unfortunately our way of getting the numbers for our equation only gets one digit.
				// This fixes that by looking ahead for numbers (via ascii numbers)
				// TODO: Find a better way of getting multi digits (REGEX)
				while ((strs[ti]+empty) >= 48 && (strs[ti]+empty) <=57 || (strs[ti]+empty) == 46) {
					fullnum += strs[ti]; 
					ti++;
				}
				int finalres = atof(fullnum.c_str()); // found on cplusplus (helpful)
			if (x == 0) {
				x = (x == 0 ? finalres : x);
			} else {
				y[ct] = finalres;
				ct++;
			}
		// Is it an operation?
		} else if (ascii >= 42 && ascii <= 43 || /*check < 40 && check > 41 &&*/ ascii == 45 || ascii == 47 /*&& check != 94 && check != 61*/) {
			op[opct] = ascii;
			opct++;
		}
	}

	// calculate!
	for (int i = 0; i < 200; i++) {
		double res = -1.36272;
		bool stahp = false;
		string strop = "";
		switch(op[i]) {
        case 42:
            res = x * y[i];
			strop = "*";
            break;
        case 43:
            res = x + y[i];
			strop = "+";
            break;
        case 45:
            res = x - y[i];
			strop = "-";
            break;
        case 47:
            res = x / y[i];
			strop = "/";
            break;
		default:
			stahp = true;
			break;
        }
		if (stahp) {
			break;
		}
		cout << "Equation #" << i+1 << ": " << x << strop << y[i] << " = " << res << endl << endl; 
		x = res; // set new result and CALCULATE FURTHER!
	}
	

	cout << "Your final answer: " << x << endl;
	system("pause");
}