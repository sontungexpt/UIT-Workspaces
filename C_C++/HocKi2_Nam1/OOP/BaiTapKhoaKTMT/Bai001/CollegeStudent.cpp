#include "CollegeStudent.h"

#pragma region Constructor
CollegeStudent::CollegeStudent()
{
	this->classLearning = "default";
	this->id = "default";
	this->phoneNumbers = "default";
	this->school = "default";
	this->specialized = "default";
}
#pragma endregion

#pragma region Properties
string CollegeStudent::GetId()
{
	return id;
}
void CollegeStudent::SetId(string value)
{
	id = value;
}
string CollegeStudent::GetClassLearning()
{
	return classLearning;
}
void CollegeStudent::SetClassLearning(string value)
{
	classLearning = value;
}
string CollegeStudent::GetPhoneNumbers()
{
	return phoneNumbers;
}
void CollegeStudent::SetPhoneNumbers(string value)
{
	phoneNumbers = value;
}
string CollegeStudent::GetSchool()
{
	return school;
}
void CollegeStudent::SetSchool(string value)
{
	school = value;
}
string CollegeStudent::GetSpecialized()
{
	return specialized;
}

void CollegeStudent::SetSpecialized(string value)
{
	specialized = value;
}

#pragma endregion

#pragma region Method
void CollegeStudent::Input()
{
	cin.ignore();
	cout << "Input full name: ";
	getline(cin,this->fullName);

	cout << "Input ID: ";
	getline(cin,this->id);
	
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
	
	cout << "Input specialized: ";
	getline(cin, this->specialized);
}
void CollegeStudent::Print()
{
	cout << "\nFull name: " << this->fullName;
	cout << "\nID: " << this->id;
	cout << "\nClass: "<< this->classLearning;
	cout << "\nBirthday: "<< this->birthDay;
	cout << "\nPhone numbers: "<< this->phoneNumbers;
	cout << "\nSchool: "<< this->school;
	cout << "\nHometown: " << this->hometown;
	cout << "\nSpecialized: " << this->specialized;
}

#pragma endregion