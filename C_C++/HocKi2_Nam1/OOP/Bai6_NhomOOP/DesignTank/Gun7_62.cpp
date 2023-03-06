#include "Gun7_62.h"

#pragma region Constructor
Gun7_62::Gun7_62()
{
	this->bulletSize = 7.62;
}
#pragma endregion

#pragma region Destructor
Gun7_62::~Gun7_62()
{
	return;
}
#pragma endregion

#pragma region Method
void Gun7_62::Shoot()
{
	cout << "\nGun " << bulletSize << "mm shoot";
}
#pragma endregion
