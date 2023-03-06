#include "ComplexNumber.h"

int main()
{
	ComplexNumber num1;
	ComplexNumber num2;

	cout << "Input first complex number: ";
	num1.Input();
	cout << "Input second complex number: ";
	num2.Input(); 
	cout << "\n(";
	num1.Print();
	cout << ") + (";
	num2.Print();
	cout << ") = ";
	ComplexNumber sum = num1.Plus(num2);
	sum.Print();
	cout << "\n(";
	num1.Print();
	cout << ") - (";
	num2.Print();
	cout << ") = ";
	ComplexNumber different = num1.Minus(num2);
	different.Print();
	cout << "\n(";
	num1.Print();
	cout << ") * (";
	num2.Print();
	cout << ") = ";
	ComplexNumber product = num1.MultipliedBy(num2);
	product.Print();
	cout << "\n(";
	num1.Print();
	cout << ") / (";
	num2.Print();
	cout << ") = ";
	ComplexNumber quotient = num1.DivideBy(num2);
	quotient.Print();
	cout << "\nModule of ";
	num1.Print();
	cout <<" = " << num1.GetModule();
	cout << "\nModule of ";
	num2.Print();
	cout << " = " << num2.GetModule();
	return 0;
}