#include "CCongTy.h"
#include "CNhanVienQuanLy.h"
#include "CNhanVienSanXuat.h"
#include "CNhanVienVanPhong.h"

void CCongTy::Nhap()
{
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai;
		cout << "Nhap loai nhan vien(0. San xuat, 1. Van phong, 2.Quan ly): ";
		cin >> loai;
		if (loai == 0)
			ds[i] = new CNhanVienSanXuat;
		else if (loai == 1)
			ds[i] = new CNhanVienVanPhong;
		else
			ds[i] = new CNhanVienQuanLy;
		ds[i]->Nhap();
	}
}

void CCongTy::Xuat()
{
	cout << "So luong nha vien la: " << n << endl;
	for (int i = 0; i < n; i++)
	{
		ds[i]->Xuat();
	}
}

void CCongTy::TinhLuong()
{
	for (int i = 0; i < n; i++)
		ds[i]->TinhLuong();
}

long CCongTy::TongLuong()
{
	long s = 0;
	for (int i = 0; i < n; i++)
		s = s + ds[i]->LayLuong();
	return s;
}

CNhanVien* CCongTy::TimKiem(string HoTenHoTen)
{
	for (int i = 0; i < n; i++)
	{
		CNhanVien* kq = ds[i]->TimKiem(HoTenHoTen);
		if (kq != NULL)
			return kq;
	}
	return NULL;
}