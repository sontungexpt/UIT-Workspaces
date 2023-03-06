#include "Sheep.h"


#pragma region Constructor
Sheep::Sheep()
{
	this->sound = "sheep sheep sheep";
}

#pragma endregion

#pragma region Properties

#pragma endregion

#pragma region Method
void Sheep::Sound()
{
	cout << "\nThe sheep say " << this->sound << " when hundry";
}

void Sheep::SetMilkAmount()
{
	this->milkAmount = rand() % (5 - 0 + 1) + 1;
}

#pragma endregion