#include "CNhanVienQuanLy.h"
#include"CNhanVien.h"
#include"CNgay.h"
#include<iostream>
using namespace std;

void CNhanVienQuanLy::Nhap()
{
	cout << "Nhap ho ten:";
	cin >> HoTen;
	cout << "Nhap ngay sinh:";
	NgaySinh.Nhap();
	cout << "Nhap luong co ban:";
	cin >> LuongCoBan;
	cout << "Nhap he so chuc vu:";
	cin >> HeSoChucVu;
	cout << "Nhap tien thuong:";
	cin >> Thuong;
}

void CNhanVienQuanLy::Xuat()
{
	cout << "\nHo ten:";
	cout << HoTen;
	cout << "\nNgay sinh:";
	NgaySinh.Xuat();
	cout << "\nLuong co ban:";
	cout << LuongCoBan;
	cout << "\nHe so chuc vu:";
	cout << HeSoChucVu;
	cout << "\nTien Thuong:";
	cout << Thuong;
	cout << "\nLuong: ";
	cout << Luong;
}

void CNhanVienQuanLy::TinhLuong()
{
	Luong = LuongCoBan * HeSoChucVu + Thuong;
}

float CNhanVienQuanLy::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVienQuanLy::TimKiem(string hoten)
{
	if (HoTen.compare(hoten) == 0)
		return this;
	return NULL;
}
