#include <iostream>
#include <string>
#include <random>

using namespace std;

void p()
{
	cout << "hi!" << endl;
	if(rand() % 0 != 0) {
		p();
	} else {
		cout << "WHOOPS" << endl;
	}
}

int main() {
	p();
	system("pause");
}