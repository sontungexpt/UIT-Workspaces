#ifndef _Controller_h
#define _Controller_h

#include "Cannon_120.h"
#include "Gun12_7.h"
#include "Gun7_62.h"
#include "Map.h"

class Controller
{
private:
	bool shootButton;
	Weapon* weapon;
	Map map;

public:
	
#pragma region Constructor
	Controller();
#pragma endregion


#pragma region Destructor
	~Controller();
#pragma endregion


#pragma region Method
	void ShowMap();
	void InitMap();
	int ChooseTarget();
	bool Shoot();
#pragma endregion

};

#endif // !_Controller_h



