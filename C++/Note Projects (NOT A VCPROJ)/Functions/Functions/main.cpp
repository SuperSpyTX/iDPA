#include <iostream>
#include <string>

using namespace std;

double add(double a, double b) {
	return a + b;
}

int main() {
	int result = add(1.5, 2.3);
	cout << result << endl;
	system("pause");
}