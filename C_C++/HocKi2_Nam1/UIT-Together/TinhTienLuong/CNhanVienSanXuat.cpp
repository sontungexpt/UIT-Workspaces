#include "CNhanVienSanXuat.h"

void CNhanVienSanXuat::Nhap()
{
	cout << "Nhap ho ten nhan vien: ";
	getline(cin, HoTen);
	cin.ignore();
	cout << "\nNhap ngay sinh: \n";
	NgaySinh.Nhap();
	cout << "Nhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "Nhap so san pham: ";
	cin >> SoSanPham;
}

void CNhanVienSanXuat::Xuat()
{
	cout << "\nNhan vien san xuat : " << endl;
	cout << "Ho ten: " << HoTen << endl;
	cout << "Ngay sinh: ";
	NgaySinh.Xuat();
	cout << "\nLuong co ban: " << LuongCoBan << endl;
	cout << "So san pham: " << SoSanPham << endl;
	cout << "Luong: " << Luong << endl;
}

void CNhanVienSanXuat::TinhLuong()
{
	Luong = LuongCoBan + SoSanPham * 2000;
}

long CNhanVienSanXuat::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVienSanXuat::TimKiem(string HoTenHoTen)
{
	if (HoTen == HoTenHoTen)
		return this;
	return NULL;
}