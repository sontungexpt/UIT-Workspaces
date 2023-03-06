#include <iostream>
#include <math.h>

using namespace std;

// initialize method
void Input(int&);
bool IsSquareNumber(int);


int main()
{
	int n;
	Input(n);
	bool result = IsSquareNumber(n);
	if (result == 1)
		cout << "La so chinh phuong";
	else
		cout << "Khong la so chinh phuon";
	return 0;
}

//method
void Input(int& nn)
{
	cout << "Nhap so nguyen n: ";
	cin >> nn;
}

bool IsSquareNumber(int nn)
{
	if (nn < 1)
	{
		return 0;
	}
	else
	{
		for (int i = 1; i*i <= nn; i++)
		{
			if (i*i == nn)
				return 1;
		}
		return 0;
	}
}