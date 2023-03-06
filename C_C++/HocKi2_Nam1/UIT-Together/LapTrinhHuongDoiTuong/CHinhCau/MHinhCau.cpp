#include "CHinhCau.h"

int main()
{
	CHinhCau A;
	cin >> A;
	cout << A;
	CHinhCau B;
	cin >> B;
	cout <<B;
	if (A == B)
		cout << "\nA bang B";
	else
		cout << "\nA khac B";
	if (A > B)
		cout << "\nA > B";
	else if (A < B)
		cout << "\nA < B";
	return 0;

}