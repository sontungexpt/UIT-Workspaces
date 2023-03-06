#include "Cow.h"

#pragma region Constructor
Cow::Cow()
{
	this->sound = "cow cow cow";
}

#pragma endregion

#pragma region Properties

#pragma endregion

#pragma region Method
void Cow::Sound()
{
	cout << "\nThe cow say " << this->sound << " when hundry";
}

void Cow::SetMilkAmount()
{
	this->milkAmount = rand() % (20 - 0 + 1) + 1;
}
#pragma endregion