#include "Cannon_120.h"

#pragma region Constructor
Cannon_120::Cannon_120()
{
	this->bulletSize = 120;
}

#pragma endregion

#pragma region Destructor
Cannon_120::~Cannon_120()
{
	return;
}
#pragma endregion

#pragma region Method
void Cannon_120::Shoot()
{
	cout << "\nCannon " << bulletSize << "mm shoot";
}
#pragma endregion