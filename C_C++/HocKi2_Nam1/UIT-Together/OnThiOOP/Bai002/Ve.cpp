#include "Ve.h"


int Ve::GetSoTroChoi()
{
	return SoTroChoi;
}

int Ve::TinhTien()
{
	return GiaTien;
}

void Ve::Nhap()
{
	cout << "\nNhap Ma Ve: ";
	cin >> this->MaSo;

	cout << "\nNhap Ho Ten: ";
	cin >> this->HoTen;

	cout << "\nNhap Nam Sinh: ";
	cin >> this->NamSinh;

	cout << "\nNhap So Tro Choi: ";
	cin >> this->SoTroChoi;
}

void Ve::Xuat()
{
	cin.ignore();
	cout << "\nMa Ve: ";
	getline(cin, this->MaSo);

	cout << "\nHo Ten: ";
	getline(cin, this->HoTen);

	cout << "\nNam Sinh: ";
	cout << this->NamSinh;

	cout << "\nSo Tro Choi: ";
	cout << this->SoTroChoi;
}