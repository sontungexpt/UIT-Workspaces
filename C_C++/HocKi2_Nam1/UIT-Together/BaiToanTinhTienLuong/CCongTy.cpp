#include "CCongTy.h"
#include"CNhanVienQuanLy.h"
#include"CNhanVienSanXuat.h"
#include"CNhanVienVanPhong.h"
#include<iostream>
using namespace std;

void CCongTy::Nhap()
{
	cout << "Nhap so luong nhan vien:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai;
		do {
		cout << "Nhap loai (0. San Xuat, 1. Van Phong 2. Quan Ly):";
		cin >> loai;
			switch (loai)
			{
			case 0: ds[i] = new CNhanVienSanXuat;
				break;
			case 1: ds[i] = new CNhanVienVanPhong;
				break;
			case 2: ds[i] = new CNhanVienQuanLy;
				break;
			}
		} while (loai != 0 && loai != 1 && loai != 2);
		
		ds[i]->Nhap();
	}
}

void CCongTy::Xuat()
{
	cout << "\n So luong nhan vien:" << n;
	for (int i = 0; i < n; i++)
		ds[i]->Xuat();
}

void CCongTy::TinhLuong()
{
	for (int i = 0; i < n; i++)
		ds[i]->TinhLuong();
}

float CCongTy::TongLuong()
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + ds[i]->LayLuong();
	return s;
}

CNhanVien* CCongTy::TimKiem(string str)
{
	for (int i = 0; i < n; i++)
	{
		CNhanVien * kq = ds[i]->TimKiem(str);
		if (kq != NULL)
			return kq;
	}
	return NULL;
}
