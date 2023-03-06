#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double xA, yA, xB, yB, xC, yC, xM,yM;
	cout << "Nhap lan luot xA, yA, xB, yB, xC, yC, xM, yM: ";
	cin >> xA >> yA >> xB >> yB >> xC >> yC >>xM>>yM;
	double SABC = abs(xA * yB + xB * yC + xC * yA - xB * yA - xC * yA - xA * yC) / 2;
	double SMAB = abs(xM * yA + xA * yB + xB * yM - yM * xA - yA * xB - yB * xM) / 2;
	double SMBC = abs(xM * yB + xB * yC + xC * yM - yM * xB - yB * xC - yC * xM) / 2;
	double SMCA = abs(xM * yC + xC * yA + xA * yM - yM * xC - yC * xA - yA * xM) / 2;
	if (SABC == SMAB + SMBC + SMCA)
		cout << "Thuoc";
	else
		cout << "Khong thuoc";

	return 0;
}