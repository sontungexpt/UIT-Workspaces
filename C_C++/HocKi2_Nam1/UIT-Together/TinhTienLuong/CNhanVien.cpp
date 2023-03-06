#include "CNhanVien.h"

void CNhanVien::Nhap()
{
	return;
}

void CNhanVien::Xuat()
{
	return;
}

void CNhanVien::TinhLuong()
{
	return;
}

long CNhanVien::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVien::TimKiem(string HoTenHoTen)
{
	if (HoTen == HoTenHoTen)
		return this;
	return NULL;
}