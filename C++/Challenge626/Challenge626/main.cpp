#include <string>
#include <iostream>

using namespace std;

double fib(double n) {
	//return fib(n-1) + fib(n-2);
	int x = 0, y = 1, z = 0, oldy = 0, it = 0;
	while (it != n) {
		z = x + y;
		x = y;
		y = z;
		it++;
		//cout << z << " - " << x << " - " << y << " - " << it << "/" << n << endl;
	}
	return z;
}

int main() {
	for(double i = 0; i < 10; i++) {
		cout << i << " - " << fib(i) << endl;
		//fib(i);
	}
	system("pause");
}