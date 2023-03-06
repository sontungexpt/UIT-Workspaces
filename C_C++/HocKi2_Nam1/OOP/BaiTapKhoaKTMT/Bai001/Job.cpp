#include "Job.h"

#pragma region Constructor
Job::Job()
{
	this->birthDay = { 1,1,1 };
	this->fullName = "default";
	this->hometown = "default";
}
//Job(string; Date, string);
#pragma endregion

#pragma region Properties
string Job::GetFullName()
{
	return fullName;
}
void Job::SetFullName(string value)
{
	fullName = value;
}
Date Job::GetBirthDay()
{
	return birthDay;
}
void Job::SetBirthDay(Date value)
{
	birthDay = value;
}
string Job::GetHomeTown()
{
	return hometown;
}
void Job::SetHomeTown(string value)
{
	hometown = value;
}
#pragma endregion

#pragma region Method
void Job::Input()
{
	return;
}
void Job::Print()
{
	return;
}
istream& operator >> (istream& is, Job& job)
{
	return is;
}
ostream& operator << (ostream& os, Job& job)
{
	return os;
}

#pragma endregion