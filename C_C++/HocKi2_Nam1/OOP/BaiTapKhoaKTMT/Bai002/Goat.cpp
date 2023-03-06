#include "Goat.h"

#pragma region Constructor
Goat::Goat()
{
	this->sound = "goat goat goat";
}

#pragma endregion

#pragma region Properties

#pragma endregion

#pragma region Method
void Goat::Sound()
{
	cout << "\nThe goat say " << this->sound << " when hundry";
}

void Goat::SetMilkAmount()
{
	this->milkAmount = rand() % (10 - 0 + 1) + 1;
}
#pragma endregion