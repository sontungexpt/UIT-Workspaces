#ifndef _Artist_h
#define _Artist_h
#include"Job.h"

class Artist:public Job
{
private:
	string artForm;
	int careerAge;

#pragma endregion

public:
#pragma region Constructor
	Artist();
#pragma endregion

#pragma region Properties
	string GetArtForm();
	void SetArtForm(string);
	int GetCareerAge();
	void SetCareerAge(int);
#pragma endregion

#pragma region Method
	void Input();
	void Print();
	
#pragma endregion
};


#endif // !_Artist_h


