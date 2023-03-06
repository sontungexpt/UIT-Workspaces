#ifndef _Officer_h
#define _Officer_h


#include <iostream>
using namespace std;


class OfficeStaff
{
private:
	int amoutOfWorkDay;
	int subsidy;//tien tro cap

public:
	int CalcWage();
	virtual OfficeStaff* FindStaff();


	friend istream& operator >> (istream&, OfficeStaff&);
	friend ostream& operator << (ostream&, OfficeStaff&);
};
#endif
