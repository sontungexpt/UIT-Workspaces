#include "Pupil.h"

#pragma region Constructor
Pupil::Pupil()
{
	this->classLearning = "default";
	this->phoneNumbers = "default";
	this->school = "default";
}
#pragma endregion

#pragma region Properties
string Pupil::GetClassLearning()
{
	return classLearning;
}
void Pupil::SetClassLearning(string value)
{
	classLearning = value;
}
string Pupil::GetPhoneNumbers()
{
	return phoneNumbers;
}
void Pupil::SetPhoneNumbers(string value)
{
	phoneNumbers = value;
}
string Pupil::GetSchool()
{
	return school;
}
void Pupil::SetSchool(string value)
{
	school = value;
}
#pragma endregion

#pragma region Method
void Pupil::Input()
{
	cin.ignore();
	cout << "Input full name: ";
	getline(cin, this->fullName);
	cout << "Input class: ";
	getline(cin, this->classLearning);
	cout << "Input birthday: ";
	cin >> this->birthDay;
	cin.ignore();
	cout << "Input phone numbers: ";
	getline(cin, this->phoneNumbers);
	cout << "Input school: ";
	getline(cin, this->school);
	cout << "Input hometown: ";
	getline(cin, this->hometown);
}
void Pupil::Print()
{
	cout << "\nFull name: " << fullName;
	cout << "\nnClass: " << classLearning;
	cout << "\nBirthday: " << birthDay;
	cout << "\nPhone numbers: " << phoneNumbers;
	cout << "\nSchool: " << school;
	cout << "\nHometown: " << hometown;
}
#pragma endregion