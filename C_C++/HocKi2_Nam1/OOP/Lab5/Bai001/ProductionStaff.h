#ifndef _ProductionStaff_h
#define _ProductionStaff_h
#include "Staff.h"

class ProductionStaff :public Staff
{
#pragma region Feilds
private:
	int basicWage;
	int productAmount;
#pragma endregion


#pragma region Method
public:
	ProductionStaff();
	void CalcWage();
	friend istream& operator >> (istream&, ProductionStaff&);
	friend ostream& operator << (ostream&, ProductionStaff&);
	void Print();

#pragma endregion

};

#endif // !_ProductionStaff_h



