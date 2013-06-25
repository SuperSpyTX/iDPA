#include <iostream>
#include <string>

using namespace std;

void func1() {
	cout << "cat" << endl;
}

void func2(int wat) {
	cout << wat << endl;
}

void func3(string a, string b) {
	cout << a << " & " << b << endl;
}

int main() {
	func1();
	func2(2);
	func3("what am i doing", "what is this");
	system("pause");
}