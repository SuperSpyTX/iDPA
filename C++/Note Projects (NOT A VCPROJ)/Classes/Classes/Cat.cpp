#include "Cat.h"

using namespace std;

Cat::Cat()
{
	name = "Tired Cat";
	age = 99;
	energyLevel = -999;
	weight = 500000000.2;
	cout << "A tired cat has been created\n";
}

Cat::Cat(string newName, int newAge, int newEnergyLevel, double newWeight)
{
	name = newName;
	age = newAge;
	energyLevel = newEnergyLevel;
	weight = newWeight * 9000;
	cout << "A new cat, " << name << ", has been created!\n";
}

// Destructor
Cat::~Cat()
{
	age = 0;
	energyLevel = 0;
	weight = 0;
	cout << name << " has been maimed in many ways that cannot be explained.\n";
	//cout << "Clifford has been maimed in many ways that cannot be explained.\n";
	// LOLOLOLOLOL
}

void Cat::Meow()
{
	cout << name << " is meowing!\n";
}

void Cat::Eat()
{
	cout << name << " is eating!\n";
	energyLevel *= 2;
	weight *= 5;
}

void Cat::Sleep(int numOfYears)
{
	cout << name << " is sleeping for " << numOfYears << "!\n";
	energyLevel *= 1000;
	age++;
	weight /= 1000;
}