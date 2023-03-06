#ifndef _Monomial_h
#define _Monomial_h
#include <iostream>
using namespace std;

class Monomial
{
#pragma region Feild
private:
	int coefficient;
	int indexNumber;

#pragma endregion

public:
#pragma region Constructor

	Monomial();
	Monomial(int, int);
	Monomial(const Monomial&);
#pragma endregion


#pragma region Properties

	int GetCoefficient();
	void SetCoefficient(int);
	int GetIndexNumber();
	void SetIndexNumber(int);

#pragma endregion

#pragma region Method
	friend istream& operator >> (istream&, Monomial&);
	friend ostream& operator << (ostream&, Monomial&);

	double CalcMonomial(double x);

#pragma endregion

};


#endif // !_Monomial_h


