#ifndef _Pupil_h
#define _Pupil_h
#include "Job.h"

class Pupil:public Job
{
private:
	string classLearning;
	string phoneNumbers;
	string school;
#pragma endregion

public:
#pragma region Constructor
	Pupil();
#pragma endregion

#pragma region Properties
	string GetClassLearning();
	void SetClassLearning(string);
	string GetPhoneNumbers();
	void SetPhoneNumbers(string);
	string GetSchool();
	void SetSchool(string);
#pragma endregion

#pragma region Method
	void Input();
	void Print();
	
#pragma endregion
};


#endif // !_Pupil_h

