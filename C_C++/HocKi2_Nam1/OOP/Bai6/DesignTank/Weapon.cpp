#include "Weapon.h"

#pragma region Constructor
Weapon::Weapon()
{
	this->bulletSize = 0;
}
Weapon::Weapon(int bulletSize)
{
	this->bulletSize = bulletSize;
}
#pragma endregion


#pragma region Destructor
Weapon::~Weapon()
{
	return;
}
#pragma endregion


#pragma region Method

double Weapon::GetBulletSize()
{
	return bulletSize;
}

void Weapon::SetBulletSize(double value)
{
	bulletSize = value;
}

void Weapon::Shoot()
{
	return;
}
#pragma endregion


