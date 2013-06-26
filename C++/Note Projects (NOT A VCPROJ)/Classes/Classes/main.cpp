// Because my dad is seriously classy
// #include <commonsense> // thanks robert, my dad's gonna need it.
#include "Cat.h";

using namespace std;

int main() {
	/*
	Cat clifford;
	
	cout << clifford.age << endl;
	cout << clifford.energyLevel << endl;
	cout << clifford.name << endl;
	cout << clifford.weight << endl;

	clifford.~Cat();
	clifford.Meow();
	
	cout << clifford.age << endl;
	cout << clifford.energyLevel << endl;
	cout << clifford.name << endl;
	cout << clifford.weight << endl;
	*/
	Cat bob("Clifford2.0", 1, 50, .3);

	cout << bob.age << endl;
	cout << bob.energyLevel << endl;
	cout << bob.name << endl;
	cout << bob.weight << endl;

	for (int i = 0; i < 30; i++) {
		// bark five times when he is hungry
		if (bob.energyLevel == 25) 
		{
			for (int o = 0; o < 5; o++) {
				bob.Meow();
			}
		}
		cout << i << " - Energy Level: " << bob.energyLevel << endl;
		bob.energyLevel--;
	}

	system("pause");
}