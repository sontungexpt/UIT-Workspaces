#include "ManagerStaff.h"


#pragma region Constructor
ManagerStaff::ManagerStaff(int positionCoefficient, int reward)
{
	this->positionCoefficient = positionCoefficient;
	this->reward = reward;
}
#pragma endregion


#pragma region Method
void ManagerStaff::CalcWage()
{
	this->wage = basicWage * positionCoefficient + reward;
}
//virtual ManagerStaff* FindStaff();
void ManagerStaff::Input()
{
	cout << "Input full name: ";
	cin.ignore();
	getline(cin, fullName);

	cout << "Input birth day: ";
	cin >> birthDay;

	cout << "Input basic wage: ";
	cin >> basicWage;

	cout << "Input position coefficient: ";
	cin >> positionCoefficient;

	cout << "Input reward: ";
	cin >> reward;

}
void ManagerStaff::Print()
{
	cout << "Full name: "<<fullName;

	cout << "Birth day: "<<birthDay;

	cout << "Basic wage: "<<basicWage;

	cout << "Position coefficient: "<<positionCoefficient;

	cout << "Reward: "<<reward;

	cout << "Wage: " << wage;
}
#pragma endregion