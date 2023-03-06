#include "MangMotChieu.h"

int main()
{
	MangMotChieu x;

	x.Input();
	x.Print();


	MangMotChieu y;
	cout << "\nNhap doi tuong 2: \n";
	y.Input();
	cout << "\nDoi tuong 2: ";
	y.Print();

	y = x;
	cout << "\nDoi tuong 2: ";
	y.Print();

	MangMotChieu d(y);
	cout << "\nDoi tuong 3: ";
	d.Print();

	cout << "\nMang sau khi cong la: ";
	d = x + y;
	cout << "\nDoi tuong 3: ";
	d.Print();

	d++;
	cout << "\nDoi tuong 3: ";
	d.Print();

	return 0;
}