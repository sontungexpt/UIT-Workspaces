#include "Tank.h"

Tank::Tank()
{
	return;
}

Tank::~Tank()
{
	return;
}

void Tank::BootTheSystem()
{
	int choice;
	do
	{
		choice = controller.ChooseTarget();
		controller.Shoot();
	} while (choice != 0);
}
