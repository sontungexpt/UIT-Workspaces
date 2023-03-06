#ifndef _Weapon_h
#define _Weapon_h
#include <iostream>

using namespace std;

class Weapon
{
protected:
	double bulletSize;

public:
#pragma region Constructor
	Weapon();
	Weapon(int);
#pragma endregion


#pragma region Destructor
	~Weapon();
#pragma endregion


#pragma region Method
	double GetBulletSize();
	void SetBulletSize(double);
	virtual void Shoot();
#pragma endregion

};


#endif // !_Weapon_h
