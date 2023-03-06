#include "Gun12_7.h"

#pragma region Constructor
Gun12_7::Gun12_7()
{
	this->bulletSize = 12.7;
}
#pragma endregion

#pragma region Destructor
Gun12_7::~Gun12_7()
{
	return;
}
#pragma endregion

#pragma region Method
void Gun12_7::Shoot()
{
	cout << "\nGun " << bulletSize << "mm shoot";
}
#pragma endregion