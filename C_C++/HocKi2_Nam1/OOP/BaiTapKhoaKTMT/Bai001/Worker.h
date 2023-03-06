#ifndef _Worker_h
#define _Worker_h
#include "Job.h"


class Worker:public Job
{
private:
	string workplace;
	int wage;
#pragma endregion

public:
#pragma region Constructor
	Worker();
#pragma endregion

#pragma region Properties
	string GetWorkplace();
	void SetWorkplace(string);
	int GetWage();
	void SetWage(int);
#pragma endregion

#pragma region Method
	void Input();
	void Print();
	friend istream& operator >> (istream&, Worker&);
	friend ostream& operator << (ostream&, Worker&);
#pragma endregion
};



#endif // !_Worker_h

