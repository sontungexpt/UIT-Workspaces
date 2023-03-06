#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double xA, yA, xB, yB, xC, yC;
	cout << "Nhap lan luot xA, yA,xB,yB,xC,yC: ";
	cin >> xA >> yA >> xB >> yB >> xC >> yC;
	double AB = sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
	double AC = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
	double BC = sqrt((xB - xC) * (xB - xC) + (yB - yC) * (yB - yC));
	if (abs(BC - AC) < AB && AB < BC + AC)
		cout << "La ba dinh cua tam giac";
	else
		cout << "Khong la ba dinh cua tam giac";
	return 0;
}