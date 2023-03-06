#include "CNhanVienQuanLy.h"

void CNhanVienQuanLy::Nhap()
{

	//cin.ignore();
	cout << "Nhap ho ten nhan vien: ";
	fflush(stdin);
	
	getline(cin, HoTen);

	cout << "\nNhap ngay sinh: \n";
	NgaySinh.Nhap();
	cout << "Nhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "Nhap he so chuc vu: ";
	cin >> HeSoChucVu;
	cout << "Nhap tien thuong: ";
	cin >> Thuong;

}

void CNhanVienQuanLy::Xuat()
{
	cout << "\nNhan vien quan ly: " << endl;
	cout << "Ho ten: " << HoTen << endl;
	cout << "Ngay sinh: ";
	NgaySinh.Xuat();
	cout << "\nLuong co ban: " << LuongCoBan << endl;
	cout << "He so chuc vu: " << HeSoChucVu << endl;
	cout << "Tien thuong: " << Thuong << endl;
	cout << "Luong: " << Luong << endl;
}

void CNhanVienQuanLy::TinhLuong()
{
	Luong = LuongCoBan * HeSoChucVu + Thuong;
}

long CNhanVienQuanLy::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVienQuanLy::TimKiem(string HoTenHoTen)
{
	if (HoTen == HoTenHoTen)
		return this;
	return NULL;
}