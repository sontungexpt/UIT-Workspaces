#include "CTapTin.h"
#include"CLuuTru.h"
#include<iostream>
using namespace std;

void CTapTin::Nhap()
{
	cout << "Nhap ten tap tin: ";
	cin >> Ten;
	cout << "Nhap ngay tao lap tap tin: \n";
	NgayLap.Nhap();
	cout << "Nhap dung luong tap tin: ";
	cin >> DungLuong;
}

void CTapTin::Xuat()
{
	cout << "\nTen thu muc: ";
	cout << Ten;
	cout << "\nNgay tao lap tap tin: ";
	NgayLap.Xuat();
	cout << "\nDung luong tap tin: ";
	cout<< DungLuong;
}

float CTapTin::TinhDungLuong()
{
	return DungLuong;
}

int CTapTin::DemTapTin()
{
	return 1;
}

int  CTapTin::DemThuMuc()
{
	return 0;
}


