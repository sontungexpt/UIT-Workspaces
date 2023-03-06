#include "Controller.h"


#pragma region Constructor
Controller::Controller()
{
	shootButton = false;
	weapon = nullptr;
}
#pragma endregion


#pragma region Destructor
Controller::~Controller()
{
	delete weapon;
	weapon = nullptr;
}
#pragma endregion


#pragma region Method
int Controller::ChooseTarget()
{
	cout << "\n1. Tank";
	cout << "\n2. Infrantry";
	cout << "\n3. Small Vehicle";
	cout << "\n0. Stop shooting";
	
	int choice = -1;
	while (choice < 0 || choice >3)
	{
		cout << "\nChoose your choice(1,2,3): ";
		cin >> choice;
	}

	switch (choice)
	{
	case Target::Tank:
		weapon = new Cannon_120;
		break;
	case Target::Infantry:
		weapon = new Gun7_62;
		break;
	case Target::SmallVehicle:
		weapon = new Gun12_7;
		break;
	default:
		break;
	}
	return choice;
}

bool Controller::Shoot()
{
	shootButton == true;
	weapon->Shoot();
	return shootButton;
}

#pragma endregion

