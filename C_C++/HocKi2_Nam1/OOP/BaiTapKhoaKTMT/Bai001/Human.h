#ifndef _Human_h
#define _Human_h
#include "Job.h"
#include "CollegeStudent.h"
#include "Pupil.h"
#include "Singer.h"
#include "Worker.h"
#include "Artist.h"

#define MAX 1000
class Human
{
private:
	int amount;
	Job* job[MAX];

public:
#pragma region Constructor
	Human();
	Human(int);
#pragma endregion


#pragma region Method
	void Input();

	void Print();
#pragma endregion

};



#endif // !_Human_h

