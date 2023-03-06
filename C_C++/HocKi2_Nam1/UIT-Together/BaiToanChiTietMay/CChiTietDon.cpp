#include "CChiTietDon.h"
#include"CChiTiet.h"
#include<iostream>
using namespace std;

void CChiTietDon::Nhap()
{
	cout << "Nhap ma so: ";
	cin >> maso;
	cout << "Nhap gia: ";
	cin >> giatien;
}

void CChiTietDon::Xuat()
{
	cout << "\nMa so: " << maso;
	cout << "\nGia: " << giatien;
}

float CChiTietDon::TinhTien()
{
	return giatien;
}

CChiTiet* CChiTietDon::TimKiem(long ms)
{
	if (maso == ms)
		return this;
	return NULL;
}

int CChiTietDon::DemChiTietDon()
{
	return 1;
}