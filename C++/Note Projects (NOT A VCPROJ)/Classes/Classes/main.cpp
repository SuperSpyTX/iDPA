// Because my dad is seriously classy
// #include <commonsense> // thanks robert, my dad's gonna need it.
#include "Cat.h";

using namespace std;

void killClifford() {
	Cat clifford("Clifford", 1, 100, -348624983762194);
}

void killTarget() {
	Cat clifford("Josh B.", 1, 100, -348624983762194);
}

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
	Cat *kappyNightmare = new Cat();

	cout << bob.getAge() << endl;
	cout << bob.getEnergy() << endl;
	cout << bob.name << endl;
	cout << bob.weight << endl;

	for (int i = 0; i < 30; i++) {
		// bark five times when he is hungry
		if (bob.getEnergy() == 25) 
		{
			for (int o = 0; o < 5; o++) {
				bob.Meow();
			}
		}
		cout << i << " - Energy Level: " << bob.getEnergy() << endl;
		bob.setEnergy(bob.getEnergy() - 1);
	}

	//bob.~Cat();
	
	killTarget(); // AH AH AH AH

	system("pause");
}