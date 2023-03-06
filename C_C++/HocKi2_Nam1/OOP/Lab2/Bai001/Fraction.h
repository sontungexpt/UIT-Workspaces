#include <iostream>
#include <math.h>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	//contrustor
	Fraction(int numerator = 1, int denominator = 1)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	int GetNumerator();
	void SetNumerator(int);
	int GetDenominator();
	void SetDenominator(int);
	Fraction Plus(Fraction);
	Fraction Minus(Fraction);
	Fraction MultipliedBy(Fraction);
	Fraction DivideBy(Fraction);
	void Print();
	void Input();
};

