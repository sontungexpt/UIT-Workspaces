#include "CPhanSo.h"

int main()
{
	CPhanSo A;
	cout << "Nhap phan so A: ";
	cin >> A;
	cout << "Phan so A: " << A;
	//A.Input();
	CPhanSo B;
	cout << "\nNhap phan so B: ";
	cin >> B;
	cout << "Phan So B: " << B;
	CPhanSo S = A + B;
	cout << "\nTong A va B: "<< S ;
	 S = A - B;
	cout << "\nHieu A va B : " << S;
	 S = A * B;
	cout << "\nTich A va B: " << S;
	 S = A / B;
	cout << "\nThuong A va B: " << S;
	if (A == B)
		cout <<"\nA bang B";
	else 
		cout << "\nA khac B";
	if (A > B)
		cout << "\nA > B";
	else if (A < B)
		cout << "\nA < B";

	//A.Print();
	return 1;
}