#ifndef _Date_h
#define _Date_h
#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
#pragma region Constructor
	Date();
	Date(int, int, int);
	Date(const Date&);

#pragma endregion

#pragma region Properties
	int GetDay();
	void SetDay(int);
	int GetMonth();
	void SetMonth(int);
	int GetYear();
	void SetYear(int);
#pragma endregion

#pragma region Method
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, Date&);

#pragma endregion


};



#endif // !_Date_h

