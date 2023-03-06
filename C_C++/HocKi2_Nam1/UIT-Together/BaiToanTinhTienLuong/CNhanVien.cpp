#include "CNhanVien.h"
#include<iostream>
#include<string>
using namespace std;

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

float CNhanVien::LayLuong()
{
	return Luong;
}

CNhanVien* CNhanVien::TimKiem(string hoten)
{
	if (HoTen.compare(hoten) == 0)
		return this;
	return NULL;
}



