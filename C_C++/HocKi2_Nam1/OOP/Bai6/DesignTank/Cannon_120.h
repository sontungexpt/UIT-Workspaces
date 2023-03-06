#ifndef _Cannon_120_h
#define _Cannon_120_h
#include "Weapon.h"

class Cannon_120:public Weapon
{
private: 



public: 
#pragma region Constructor
	Cannon_120();

#pragma endregion

#pragma region Destructor
	~Cannon_120();
#pragma endregion

#pragma region Method
	void Shoot();
#pragma endregion
	
};


#endif // !_Cannon_120_h


