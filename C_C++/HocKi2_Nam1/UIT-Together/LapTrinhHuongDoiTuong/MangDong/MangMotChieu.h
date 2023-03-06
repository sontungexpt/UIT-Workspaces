#ifndef _MangMotChieu_h
#define _MangMotChieu_h

#include <iostream>
#include <iomanip>
using namespace std;

class MangMotChieu
{
private:
	int* a;
	int n;

public:

#pragma region Constructor
	MangMotChieu();
	MangMotChieu(const MangMotChieu&);
#pragma endregion


#pragma region Destructor
	~MangMotChieu();

#pragma endregion



#pragma region Method
	void Input();
	void Print();

	MangMotChieu& operator= (const MangMotChieu&);
	MangMotChieu operator+ (const MangMotChieu&);
	MangMotChieu& operator++ (int );


#pragma endregion
};


#endif // !_MangMotChieu_h


