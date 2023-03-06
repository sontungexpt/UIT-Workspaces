#include "Worker.h"

#pragma region Constructor
Worker::Worker()
{
	this->workplace = "default";
	this->wage = 0;
}
#pragma endregion

#pragma region Properties

string Worker::GetWorkplace()
{
	return workplace;
}
void Worker::SetWorkplace(string value)
{
	workplace = value;
}
int Worker::GetWage()
{
	return wage;
}
void Worker::SetWage(int value)
{
	wage = value;
}

#pragma endregion

#pragma region Method
void Worker::Input()
{
	cin.ignore();
	cout << "Input full name: ";
	getline(cin, this->fullName);

	cout << "Input birthday: ";
	cin >> this->birthDay;
	
	cin.ignore();
	cout << "Input hometown: ";
	getline(cin, this->hometown);

	cout << "Input workplace: ";
	getline(cin, this->workplace);
	
	cout << "Input wage: ";
	cin >> wage;
}
void Worker::Print()
{
	cout << "\nFull name: " << fullName;
	cout << "\nBirthday: " << birthDay;
	cout << "\nHometown: " << hometown;
	cout << "\nWorkplace: " << workplace;
	cout << "\nWage: " << wage;
}

#pragma endregion