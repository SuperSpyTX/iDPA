#include <string>
#include <iostream>

using namespace std;

class Cat
{
private:
	int age, energyLevel; // so tired
public:
	// Initialize Variables
	string name;
	double weight;

	Cat();
	Cat(string newName, int newAge, int newEnergyLevel, double newWeight);
	~Cat();

	// Methods (Functions)
	void Meow();
	void Eat(); // gotem
	void Sleep(int numOfYears); // indeed.
	int getAge();
	int getEnergy();
	int getCatYears();
	void setAge(int val);
	void setEnergy(int val);
	void setCatYears(int val);

};

