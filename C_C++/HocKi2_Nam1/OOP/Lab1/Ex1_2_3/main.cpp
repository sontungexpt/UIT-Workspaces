#include <iostream>
#include <conio.h>

using namespace std;



struct Fraction {

	//fields
	int numerator;
	int denominator;

	//constructor
	Fraction() {};
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	};
};
typedef struct Fraction Fraction;


void Pause();

int FindGcd(int num1, int num2);

void InputFraction(Fraction& fraction);

void PrintFraction(Fraction fraction);

Fraction ShortenTheFraction(Fraction fraction);

Fraction FormatTheFraction(Fraction fraction);

Fraction FindGreaterFraction(Fraction fraction1, Fraction fraction2);

Fraction Sum(Fraction fraction1, Fraction fraction2);

Fraction Different(Fraction fraction1, Fraction fraction2);

Fraction Product(Fraction fraction1, Fraction fraction2);

Fraction Quotient(Fraction fraction1, Fraction fraction2);

bool AlertErrorDividedByZero(Fraction fraction);

int main()
{
	char key = 0;
	char choice = 0;
	Fraction fraction;
	Fraction fraction1;
	Fraction fraction2;
	do {
		//Begin Menu
		system("cls");
		cout << "1. Exercise 1 (Input Fraction, Shorten The Fraction, Print Reusult).\n";
		cout << "2. Exercise 2 (Input Two Fraction, Find The Max Fraction, Print Result).\n";
		cout << "3. Exercise 3 (Input Two Fraction, Print Sum & Diffeent & Product & Quotient ).\n";
		cout << "ESC: Exit\n";
		cout << "\nChoose your choice.";
		//End Menu

		key = _getch();
		switch (key)
		{
			case '1': //Exercise 1
			{
				system("cls");
				cout << "--------------Exercise 1--------------" << endl;
				cout << "\nFraction: " << endl;
				do
				{
					InputFraction(fraction);
				} while (AlertErrorDividedByZero(fraction));
				cout << "\nShorted Fraction: ";
				PrintFraction(ShortenTheFraction(FormatTheFraction(fraction)));
				Pause();
				break;
			}
			case '2'://Exercise 2
			{
				system("cls");
				cout << "--------------Exercise 2--------------" << endl;
				cout << "\nFraction 1" << endl;
				do
				{
					InputFraction(fraction1);
				} while (AlertErrorDividedByZero(fraction1));
				cout << "\nFraction 2" << endl;
				do
				{
					InputFraction(fraction2);
				} while (AlertErrorDividedByZero(fraction2));
				PrintFraction(FormatTheFraction(FindGreaterFraction(fraction1, fraction2)));
				Pause();
				break;
			}
			case '3': //Excersie 3
			{
				system("cls");
				cout << "--------------Bai 3--------------";
				cout << "\nFraction 1" << endl;
				do
				{
					InputFraction(fraction1);
				} while (AlertErrorDividedByZero(fraction1));
				cout << "\nFraction 2" << endl;
				do
				{
					InputFraction(fraction2);
				} while (AlertErrorDividedByZero(fraction2));
				cout << "\nSum: ";
				PrintFraction(Sum(fraction1, fraction2));
				cout << "\nDifferent: ";
				PrintFraction(Different(fraction1, fraction2));
				cout << "\nProduct ";
				PrintFraction(Product(fraction1, fraction2));
				cout << "\nQuotient: ";
				PrintFraction(Quotient(fraction1, fraction2));
				Pause();
				break;
			}
			case 27:
			{
				system("cls");
				cout << "Are you sure to break the program?\n";
				cout << "Yes: Enter.\n";
				cout << "Back To Home: ESC.\n";
				do
				{
					choice = _getch();
					switch (choice)
					{
					case 13:
					{
						exit(0);
						break;
					}
					case 27:
					{
						key = 0;
						break;
					}
					default:
					{
						break;
					}
					}
				} while (choice != 13 && choice != 27);
				break;
			}
			default:
			{
				break;
			}
		}
	} while (key != 27);
	return 0;
}

int FindGcd(int num1, int num2)
{
	num1 = abs(num1);
	num2 = abs(num2);
	while (num1*num2 != 0)
	{
		if (num1 > num2)
			num1 %= num2;
		else num2 %= num1;
	}
	return num1 + num2;
}

void InputFraction(Fraction &fraction)
{
	cout << "\nInput numerator: ";
	cin >> fraction.numerator;
	cout << "Input denominator: ";
	cin >> fraction.denominator;
}

void PrintFraction(Fraction fraction)
{
	if (fraction.denominator == 1)
		cout << fraction.numerator;
	else
		cout << fraction.numerator << "/" << fraction.denominator;
}

Fraction ShortenTheFraction(Fraction fraction)
{
	int gcd = FindGcd(fraction.numerator, fraction.denominator);
	fraction.numerator /= gcd;
	fraction.denominator /= gcd;
	return fraction;
}

Fraction FormatTheFraction(Fraction fraction)
{
	if (fraction.numerator * fraction.denominator >= 0)
	{
		fraction.numerator = abs(fraction.numerator);
		fraction.denominator = abs(fraction.denominator);
	}
	else
	{
		fraction.numerator = -abs(fraction.numerator);
		fraction.denominator = abs(fraction.denominator);
	}
	return fraction;
}

Fraction FindGreaterFraction(Fraction fraction1, Fraction fraction2)
{
	if ((float)(fraction1.numerator / fraction1.denominator) > (float)(fraction2.numerator / fraction2.denominator))
	{
		return fraction1;
	}
	else
	{
		return fraction2;
	}

}

Fraction Sum(Fraction fraction1, Fraction fraction2)
{
	Fraction sum;
	sum.numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
	sum.denominator = fraction1.denominator * fraction2.denominator;
	return FormatTheFraction(ShortenTheFraction(sum));
}

Fraction Different(Fraction fraction1, Fraction fraction2)
{
	Fraction different;
	different.numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
	different.denominator = fraction1.denominator * fraction2.denominator;
	return FormatTheFraction(ShortenTheFraction(different));
}

Fraction Product(Fraction fraction1, Fraction fraction2)
{
	Fraction product;
	product.numerator = fraction1.numerator * fraction2.numerator;
	product.denominator = fraction1.denominator * fraction2.denominator;
	return FormatTheFraction(ShortenTheFraction(product));
}

Fraction Quotient(Fraction fraction1, Fraction fraction2)
{
	Fraction quotient;
	quotient.numerator = fraction1.numerator * fraction2.denominator;
	quotient.denominator = fraction1.denominator * fraction2.numerator;
	return FormatTheFraction(ShortenTheFraction(quotient));
}

void Pause()
{
	cout << "\nNhan Enter De Tiep Tuc Chuong Trinh!\n";
	char enter;
	do
	{
		enter = _getch();
	} while (enter != 13);
}

bool AlertErrorDividedByZero(Fraction fraction)
{
	if (fraction.denominator == 0)
	{
		cout << "\nCan Not Divide By Zero. Try again.\n";
		return 1;
	}
	return 0;
}
