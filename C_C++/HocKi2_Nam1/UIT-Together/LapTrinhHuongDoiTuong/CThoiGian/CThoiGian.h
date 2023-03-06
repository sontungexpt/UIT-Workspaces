#pragma once
#include <iostream>
#include <math.h>

using namespace std;
class CThoiGian
{
private:
	int hour;
	int minute;
	int second;

public:
	//constructor
	CThoiGian();
	CThoiGian(int, int , int);
	CThoiGian(const CThoiGian &);

	//destructor
	~CThoiGian();

	//method
	void Input();
	void Print();
	bool IsInvalidTime();
	CThoiGian FindNextTime();
	CThoiGian FindPreviousTime();
	int NumberOfSecond();
	int Distance(CThoiGian);
	int Compare(CThoiGian);
	friend istream& operator >> (istream&, CThoiGian&);
	friend ostream& operator << (ostream&, CThoiGian&);
};

