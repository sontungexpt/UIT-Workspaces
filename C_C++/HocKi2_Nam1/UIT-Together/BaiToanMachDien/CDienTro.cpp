#include "CDienTro.h"
#include<iostream>
using namespace std;

void CDienTro::Nhap()
{
	cout << "\nNhap ma so thiet bi: ";
	cin >> MaSo;
	cout << "Nhap do do dien tro: ";
	cin >> R;
}

void CDienTro::Xuat()
{
	cout << "\nMa so thiet bi: ";
	cout << MaSo;
	cout << "\nDo do dien tro: ";
	cout << R;
}

float CDienTro::TinhDienTro()
{
	return R;
}
