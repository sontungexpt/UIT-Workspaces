#ifndef _Singer_h
#define _Singer_h
#include "Job.h"


class Singer:public Job
{
	
private:
	string songType;
	int careerAge;
#pragma endregion

public:
#pragma region Constructor
	Singer();
#pragma endregion

#pragma region Properties
	string GetSongType();
	void SetSongType(string);
	int GetCareerAge();
	void SetCareerAge(int);
#pragma endregion

#pragma region Method
	void Input();
	void Print();
	
#pragma endregion
};

#endif // !_Singer_h
