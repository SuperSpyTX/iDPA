#include <string>
#include <iostream>

using namespace std;


int main() {
	int size = 0;
	cout << "What is the size of the array?: ";
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		int input;
		cout << "What should I put for array index " << i << "?" << endl;
		cin >> input;
		arr[i] = input;
	}

	cout << "Here are the results: " << endl << endl;
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "] = " << *(arr + i) << endl;
	}

	system("pause");
}