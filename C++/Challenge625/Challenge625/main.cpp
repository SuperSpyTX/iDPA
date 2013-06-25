#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
	// def vars
	int arr[150];
	double fillar = 1;

	// fill it.
	/*for (int i = 0; i < 150; i++) {
		arr[i] = (fillar *= 2);
		cout << arr[i] << " - E: " << i << endl;
	}*/

	// Dragon's Mini Challenge
	for (int i = 0; i < 150; i++) {
		arr[i] = (rand() * 1);
		cout << arr[i] << " - E: " << i;
		if (arr[i-1] == arr[i]) {
			arr[i] *= 2;
			cout << " - H" << endl;
		} else {
			cout << endl;
		}
	}

	system("pause");
}