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
	Date(int day, int month, int year);
	Date(const Date&);
#pragma endregion


#pragma region Destructor
	~Date();
#pragma endregion


#pragma region Method
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, Date&);
#pragma endregion
	
};

#endif // !_Date_h


