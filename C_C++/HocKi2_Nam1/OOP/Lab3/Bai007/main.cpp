#include"../Bai005/Stack.h"
#include <string>

string ChangeToHexa(int);
string ChangeToOctal(int);
string ChangeToBinary(int);
char ConvertToChar(short int);

int main()
{
	int n;
	cout << "Input the Decimal number : ";
	cin >> n;
	cout << "\nThe Hexa number: " << ChangeToHexa(n);
	cout << "\nThe Octal number: " << ChangeToOctal(n);
	cout << "\nThe Binary number: " << ChangeToBinary(n);
	return 0;
}

string ChangeToHexa(int decimal)
{
	Stack stored;
	string hexa = "";
	while (decimal > 0)
	{
		int left = decimal % 16;
		stored.Push(left);
		decimal /= 16;
	}
	while (!stored.IsEmpty())
		hexa += ConvertToChar(stored.Pop());
	return hexa;
}
string ChangeToOctal(int decimal)
{
	Stack stored;
	string hexa = "";
	while (decimal > 0)
	{
		int left = decimal % 8;
		stored.Push(left);
		decimal /= 8;
	}
	while (!stored.IsEmpty())
		hexa += ConvertToChar(stored.Pop());
	return hexa;
}

string ChangeToBinary(int decimal)
{
	Stack stored;
	string hexa = "";
	while (decimal > 0)
	{
		int left = decimal % 2;
		stored.Push(left);
		decimal /= 2;
	}
	while (!stored.IsEmpty())
		hexa += ConvertToChar(stored.Pop());
	return hexa;
}

char ConvertToChar(short int n)
{
	if (n == 0)
		return '0';
	else if (n == 1)
		return '1';
	else if (n == 2)
		return '2';
	else if (n == 3)
		return '3';
	else if (n == 4)
		return '4';
	else if (n == 5)
		return '5';
	else if (n == 6)
		return '6';
	else if (n == 7)
		return '7';
	else if (n == 8)
		return '8';
	else if (n == 9)
		return'9';
	else if (n == 10)
		return 'A';
	else if (n == 11)
		return 'B';
	else if (n == 12)
		return 'C';
	else if (n == 13)
		return 'D';
	else if (n == 14)
		return 'E';
	return 'F';
}