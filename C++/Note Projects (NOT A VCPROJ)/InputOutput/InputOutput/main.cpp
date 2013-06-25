#include <iostream>
#include <string>

using namespace std;

string enc(string str) {

	return "";
}

int main() {
	string x;
	cout << "Please enter a secret message: ";
	cin >> x; // input
	cout << "Oops I exposed your secret message: " << x;
	system("pause");
	cout << "Now that looks much better: " << enc(x);
	system("pause");
}