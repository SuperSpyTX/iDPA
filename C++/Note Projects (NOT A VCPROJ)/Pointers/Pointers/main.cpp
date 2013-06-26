#include <string>
#include <iostream>

using namespace std;

int main() {
	int x = 3;
	int* arr = new int[x];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;

	cout << arr[0] << arr[1] << arr[2] << endl;
	cout << *arr << endl;

	system("pause");
}