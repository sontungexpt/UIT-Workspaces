#ifndef _Gun7_62_h
#define _Gun7_62_h
#include "Weapon.h"
class Gun7_62: public Weapon
{
private:

public: 
#pragma region Constructor
	Gun7_62();
#pragma endregion

#pragma region Destructor
	~Gun7_62();
#pragma endregion

#pragma region Method
	void Shoot();
#pragma endregion

	
};

#endif // !_Gun7_62_h
