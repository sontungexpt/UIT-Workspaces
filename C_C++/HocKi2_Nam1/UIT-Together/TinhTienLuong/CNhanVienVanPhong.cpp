#include "CNhanVienVanPhong.h"

void CNhanVienVanPhong::Nhap()
{
	cout << "Nhap ho ten nhan vien: ";
	getline(cin, HoTen);
	cin.ignore();
	cout << "\nNhap ngay sinh: \n";
	NgaySinh.Nhap();
	cout << "Nhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "Nhap so ngay lam viec: ";
	cin >> SoNgayLamViec;
	cout << "Nhap tro cap: ";
	cin >> TroCap;
}

void CNhanVienVanPhong::Xuat()
{
	cout << "\nNhan vien van phong: " << endl;
	cout << "Ho ten: " << HoTen << endl;
	cout << "Ngay sinh: ";
	NgaySinh.Xuat();
	cout << "\nLuong co ban: " << LuongCoBan << endl;
	cout << "So ngay lam viec: " << SoNgayLamViec << endl;
	cout << "Nhap tro cap: " << TroCap << endl;
	cout << "Luong: " << Luong << endl;
}

void CNhanVienVanPhong::TinhLuong()
{
	Luong = LuongCoBan + SoNgayLamViec * 100000 + TroCap;
}

long CNhanVienVanPhong::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVienVanPhong::TimKiem(string HoTenHoTen)
{
	if (HoTen == HoTenHoTen)
		return this;
	return NULL;
}