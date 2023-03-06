#include "Fraction.h"

int main()
{
	Fraction fraction1;
	Fraction fraction2;
	cout << "Input first fraction: ";
	fraction1.Input();
	cout <<"Input second fraction: ";
	fraction2.Input();
	cout << "\nfraction 1 + fraction 2 = ";
	Fraction sum = fraction1.Plus(fraction2);
	sum.Print();
	cout << "\nfraction 1 - fraction 2 = ";
	Fraction different = fraction1.Minus(fraction2);
	different.Print();
	cout << "\nfraction 1 * fraction 2 = ";
	Fraction product = fraction1.MultipliedBy(fraction2);
	product.Print();
	cout << "\nfraction 1 / fraction 2 = ";
	Fraction quotient = fraction1.DivideBy(fraction2);
	quotient.Print();
	return 0;
}