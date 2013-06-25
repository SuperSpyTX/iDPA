#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int x;
	cin >> x;
	
	// one way
	if (x < 10) {
		cout << "The result of x = " << x << " is less than 10." << endl;
	} else if (x == 10) {
		cout << "The result of x = " << x << " is exactly equal to 10." << endl;
	} else {
		cout << "The result of x = " << x << " is greater than 10." << endl;
	}

	// second way (specific though)
	switch (x) {
	case 1:

	}

	bool st = (x = 10 ? true : false);

	system("pause");
}