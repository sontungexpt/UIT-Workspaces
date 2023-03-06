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

	//constructor
	Date();
	Date(int day, int month, int year);
	Date(const Date&);

	//destructor
	~Date();


	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, Date&);
};


#endif // !_Date_h


