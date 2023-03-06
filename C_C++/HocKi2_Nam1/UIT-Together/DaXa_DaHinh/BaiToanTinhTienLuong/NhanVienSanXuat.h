#ifndef _NhanVienSanXuat_h
#define _NhanVienSanXuat_h

#include <iostream>

using namespace std;


class ProductionStaff
{

private: 
	int amountOfProduct;


public:

	int CalcWage();
	ProductionStaff* FindStaff();
	friend istream& operator >> (istream&, ProductionStaff&);
	friend ostream& operator << (ostream&, ProductionStaff&);


};
#endif

