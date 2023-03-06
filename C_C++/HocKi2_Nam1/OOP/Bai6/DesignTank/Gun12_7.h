#ifndef _Gun12_7_h
#define _Gun12_7_h
#include "Weapon.h"

class Gun12_7:public Weapon
{
private:
	

public:
#pragma region Constructor
	Gun12_7();
#pragma endregion

#pragma region Destructor
	~Gun12_7();
#pragma endregion

#pragma region Method
	void Shoot();
#pragma endregion

};

#endif // !_Gun12_7_h
