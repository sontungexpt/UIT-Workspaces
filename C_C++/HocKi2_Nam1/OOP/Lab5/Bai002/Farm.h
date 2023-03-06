#ifndef _Farm_h
#define _Farm_h
#include "Catle.h"
#include "Cow.h"
#include "Sheep.h"
#include "Goat.h"
#include <vector>
class Farm
{
private:
	int amountOfCow;
	int amountOfSheep;
	int amountOfGoat;
	vector<vector<Catle*>> catles;

public:
	void Input();

	int GetNumbersOf(string);

	int GetNumberOfMilk();

	void Sound();

	void Print();
};


#endif // !_Farm_h

