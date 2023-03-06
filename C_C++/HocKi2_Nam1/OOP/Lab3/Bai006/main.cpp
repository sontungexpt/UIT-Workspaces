#include "../Bai005/Stack.h"


bool IsPrimeNumber(int);
void FactorizePrimeNumber(int);

int main()
{
	cout << "Input the number which you want to factorize prime number: ";
	int n;
	cin >> n;
	FactorizePrimeNumber(n);
	return 0;
}

bool IsPrimeNumber(int value)
{
	if (value <= 1)
		return 0;
	else
	{
		for (int i = 2; i < value; i++)
			if (value % i == 0)
				return 0;
		return 1;
	}
}

void FactorizePrimeNumber(int value)
{
	Stack primeNumbers;

	while (value > 1)
	{
		int i = 2;
		while (i <= value)
		{
			if (value % i == 0)
				if (IsPrimeNumber(i))
				{
					value /= i;
					primeNumbers.Push(i);
					break;
				}
			i++;
		}

	}
	while (primeNumbers.Count() > 0)
	{
		if (primeNumbers.Count() == 1)
			cout << primeNumbers.Pop();
		else
			cout << primeNumbers.Pop() << "*";
	}
}