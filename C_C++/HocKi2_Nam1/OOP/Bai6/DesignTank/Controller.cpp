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
	map.Close();
}
#pragma endregion


#pragma region Method
void Controller::ShowMap()
{
	map.ShowMap({ 0,0 });
}

int Controller::ChooseTarget()
{
	Coord choice = {-1,-1};
	while (true)
	{
		Graphic::GoTo(Graphic::wherex(), Graphic::wherey() + 1);
		cout << "\nChoose your coordinate of target ("<<SMALL_VEHICLE<<": small vehicle, "<<INFANTRY<<": infantry, "<<TANK <<": tank): ";
		cin >> choice;
		if ((choice.X >= 0 && choice.X < map.GetWidth()) && (choice.Y >= 0 && choice.Y < map.GetHeight()))
			break;
	}

	switch (map.GetValueAt(choice))
	{
	case TANK:
		weapon = new Cannon_120;
		map.SetValueAt(choice, EMPTY_POSITION);
		map.SetExistedAt(choice);
		break;
	case INFANTRY:
		weapon = new Gun7_62;
		map.SetValueAt(choice, EMPTY_POSITION);
		map.SetExistedAt(choice);

		break;
	case SMALL_VEHICLE:
		weapon = new Gun12_7;
		map.SetValueAt(choice, EMPTY_POSITION);
		map.SetExistedAt(choice);

		break;
	default:
		return 0;
		break;
	}
	return 1;
}

bool Controller::Shoot()
{
	shootButton == true;
	cout << endl << endl<<endl;
	//Graphic::GoTo(Graphic::wherex(), Graphic::wherey()+6);
	weapon->Shoot();
	return shootButton;
}

void Controller::InitMap()
{
	srand(time(NULL));
	map.Init();
	int amountOfTarget = map.RandomAmountOfTarget();
	for (int i=1;i<=amountOfTarget;i++)
		map.RandomTargetPosition(map.RandomTypeOfTarget());
}

#pragma endregion

