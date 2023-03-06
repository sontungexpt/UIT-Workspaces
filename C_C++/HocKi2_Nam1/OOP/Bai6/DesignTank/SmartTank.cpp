#include "SmartTank.h"

SmartTank::SmartTank()
{
	return;
}

SmartTank::~SmartTank()
{
	return;
}

void SmartTank::BootTheSystem()
{
	controller.InitMap();
	char key;
	do
	{
		system("cls");
		controller.ShowMap();
		bool success = controller.ChooseTarget();
		if (success == true)
		{
			system("cls");
			controller.ShowMap();
			controller.Shoot();
		}
		else
		{
			system("cls");
			controller.ShowMap();
			cout << "\n\n\nThere are no enemies at this location";
		}
		do
		{
			//Graphic::GoTo(0, Graphic::wherey() + 3);
			cout << "\n\nDo you want to continue shoot: ";
			cout << "\nEnter: YES, ESC: NO";
			key = _getch();
		} while (key != 13 && key != 27);
		
	} while (key!=27);
	
}


