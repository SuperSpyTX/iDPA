#include <string>
#include <iostream>

using namespace std;

class Cat
{
public:
	// Initialize Variables
	string name;
	int age, energyLevel; // so tired
	double weight;

	Cat();
	Cat(string newName, int newAge, int newEnergyLevel, double newWeight);
	~Cat();

	// Methods (Functions)
	void Meow();
	void Eat(); // gotem
	void Sleep(int numOfYears); // indeed.

};

