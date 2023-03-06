#ifndef _Controller_h
#define _Controller_h
#include "Cannon_120.h"
#include "Gun12_7.h"
#include "Gun7_62.h"

class Controller
{
private:
	bool shootButton;
	Weapon* weapon;
	
public:
	static enum Target
	{
		Tank = 1,
		Infantry,
		SmallVehicle,
	};
#pragma region Constructor
	Controller();
#pragma endregion


#pragma region Destructor
	~Controller();
#pragma endregion


#pragma region Method
	int ChooseTarget();
	bool Shoot();
#pragma endregion

};

#endif // !_Controller_h



