#include "CNhanVienSanXuat.h"
#include"CNgay.h"
#include<iostream>
using namespace std;

void CNhanVienSanXuat::Nhap()
{
	cout << "Nhap ho ten:";
	cin >> HoTen;
	cout << "Nhap ngay sinh:";
	NgaySinh.Nhap();
	cout << "Nhap luong co ban:";
	cin >> LuongCoBan;
	cout << "Nhap so san pham:";
	cin >> SoSanPham;
}

void CNhanVienSanXuat::Xuat()
{
	cout << "\nHo ten:";
	cout << HoTen;
	cout << "\nNgay sinh:";
	NgaySinh.Xuat();
	cout << "\nLuong co ban:";
	cout << LuongCoBan;
	cout << "\nSo san pham:";
	cout << SoSanPham;
	cout << "\nLuong: ";
	cout << Luong;
}

void CNhanVienSanXuat::TinhLuong()
{
	Luong = LuongCoBan + SoSanPham * 2000;
}

float CNhanVienSanXuat::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVienSanXuat::TimKiem(string hoten)
{
	if (HoTen.compare(hoten) == 0)
		return this;
	return NULL;
}