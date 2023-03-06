#include "CNhanVienVanPhong.h"
#include"CNhanVien.h"
#include<iostream>
using namespace std;

void CNhanVienVanPhong::Nhap()
{
	cout << "Nhap ho ten:";
	cin >> HoTen;
	cout << "Nhap ngay sinh:";
	NgaySinh.Nhap();
	cout << "Nhap luong co ban:";
	cin >> LuongCoBan;
	cout << "Nhap so ngay lam viec:";
	cin >> SoNgayLamViec;
	cout << "Nhap tro cap:";
	cin >> TroCap;
}

void CNhanVienVanPhong::Xuat()
{
	cout << "\nHo ten:";
	cout << HoTen;
	cout << "\nNgay sinh:";
	NgaySinh.Xuat();
	cout << "\nLuong co ban:";
	cout << LuongCoBan;
	cout << "\nSo ngay lam viec:";
	cout << SoNgayLamViec;
	cout << "\nTro cap:";
	cout << TroCap;
	cout << "\nLuong: ";
	cout << Luong;
}

void CNhanVienVanPhong::TinhLuong()
{
	Luong = LuongCoBan + SoNgayLamViec * 200000 + TroCap;
}

float CNhanVienVanPhong::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVienVanPhong::TimKiem(string hoten)
{
	if (HoTen.compare(hoten) == 0)
		return this;
	return NULL;
}
