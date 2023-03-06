#ifndef _CollegeStudent_h
#define _CollegeStudent_h
#include "Job.h"

class CollegeStudent : public Job
{
#pragma region Feilds
private:
	string id;
	string classLearning;
	string phoneNumbers;
	string school;
	string specialized;
#pragma endregion

public:
#pragma region Constructor
	CollegeStudent();
#pragma endregion

#pragma region Properties
	string GetId();
	void SetId(string);
	string GetClassLearning();
	void SetClassLearning(string);
	string GetPhoneNumbers();
	void SetPhoneNumbers(string);
	string GetSchool();
	void SetSchool(string);
	string GetSpecialized();
	void SetSpecialized(string);
#pragma endregion

#pragma region Method
	void Input();
	void Print();
	friend istream& operator >> (istream&, CollegeStudent&);
	friend ostream& operator << (ostream&, CollegeStudent&);
#pragma endregion

};


#endif // !_CollegeStudent_h

