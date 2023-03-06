#include "CHonSo.h"


int main()
{
	CHonSo A;
	cout << "Nhap hon so A: ";
	cin >> A;
	cout << "\nHon So A: "<< A;

	CHonSo C;
	C = A;
	cout << "\nHon so B la: ";
	cout << C;

	CHonSo B(3, 4, 5);
	cout << "Hon So C: " << B;

	CHonSo D(C);
	cout << "Hon so D: " << D;


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