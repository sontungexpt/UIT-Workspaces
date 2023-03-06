#include "Singer.h"

#pragma region Constructor
Singer::Singer()
{
	this->songType = "default";
	this->careerAge = 0;
}
#pragma endregion

#pragma region Properties
string Singer::GetSongType()
{
	return songType;
}
void Singer::SetSongType(string value)
{
	songType = value;
}
int Singer::GetCareerAge()
{
	return careerAge;
}
void Singer::SetCareerAge(int value)
{
	careerAge = value;
}
#pragma endregion

#pragma region Method
void Singer::Input()
{
	cin.ignore();
	cout << "Input full name: ";
	getline(cin, this->fullName);
	
	cout << "Input birthday: ";
	cin >> this->birthDay;
	
	cin.ignore();
	cout << "Input hometown: ";
	getline(cin, this->hometown);
	
	cout << "Input song type: ";
	getline(cin, this->songType);
	
	cout << "Input career age: ";
	cin >> careerAge;
}

void Singer::Print()
{
	cout << "\nFull name: " << fullName;
	cout << "\nBirthday: " << birthDay;
	cout << "\nHometown: " << hometown;
	cout << "\nSong type: " << songType;
	cout << "\nCareer age: " << careerAge;
}

#pragma endregion