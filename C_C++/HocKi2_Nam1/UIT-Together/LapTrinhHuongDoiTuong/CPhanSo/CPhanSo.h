#pragma once
#include <iostream>
using namespace std;

class CPhanSo
{
private:
	int Tu;
	int Mau;

public:
	//constructor
	CPhanSo();
	CPhanSo(int, int);
	CPhanSo(const CPhanSo&);

	//destructor
	~CPhanSo();

	//method
	void Input();
	void Print();
	int XetDau();
	int CompareWith(CPhanSo);
	CPhanSo Shorten();
	CPhanSo Plus(CPhanSo);
	CPhanSo Minus(CPhanSo);
	CPhanSo MultipliedBy(CPhanSo);
	CPhanSo DivideBy(CPhanSo);

	//overload operator
	friend istream& operator >> (istream&, CPhanSo&);
	friend ostream& operator << (ostream&, CPhanSo&);
	CPhanSo operator + (CPhanSo);
	CPhanSo operator - (CPhanSo);
	CPhanSo operator * (CPhanSo);
	CPhanSo operator / (CPhanSo);
	bool  operator > (CPhanSo);
	bool  operator < (CPhanSo);
	bool operator == (CPhanSo);
	bool  operator != (CPhanSo);
	bool  operator >= (CPhanSo);
	bool  operator <= (CPhanSo);


};

