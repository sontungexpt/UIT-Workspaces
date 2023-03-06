#include "Artist.h"

#pragma region Constructor
Artist::Artist()
{
	this->artForm = "default";
	this->careerAge = 0;
}
#pragma endregion

#pragma region Properties
string Artist::GetArtForm()
{
	return artForm;
}
void Artist::SetArtForm(string value)
{
	artForm = value;
}
int Artist::GetCareerAge()
{
	return careerAge;
}
void Artist::SetCareerAge(int value)
{
	careerAge = value;
}
#pragma endregion

#pragma region Method
void Artist::Input()
{
	cin.ignore();
	cout << "Input full name: ";
	getline(cin, this->fullName);

	cout << "Input birthday: ";
	cin >> this->birthDay;
	
	cin.ignore();
	cout << "Input hometown: ";
	getline(cin, this->hometown);

	cout << "Input art form: ";
	getline(cin, this->artForm);

	cout << "Input career age: ";
	cin >> careerAge;
}
void Artist::Print()
{
	cout << "\nFull name: " << fullName;
	cout << "\nBirthday: " << birthDay;
	cout << "\nHometown: " << hometown;
	cout << "\nSong type: " << artForm;
	cout << "\nCareer age: " << careerAge;
}

#pragma endregion
