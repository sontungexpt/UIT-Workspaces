#include "CChiTietPhuc.h"
#include"CChiTiet.h"
#include"CChiTietDon.h"
#include<iostream>
using namespace std;

void CChiTietPhuc::Nhap()
{
	cout << "Nhap ma so: ";
	cin >> maso;
	cout << "Nhap so luong chi tiet thanh phan: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai;
		cout << "Nhap loai (0.Don, 1.Phuc):";
		cin >> loai;
		switch (loai)
		{
		case 0: ds[i] = new CChiTietDon;
			break;
		case 1: ds[i] = new CChiTietPhuc;
			break;
		}
		ds[i]->Nhap();
	}
}

void CChiTietPhuc::Xuat()
{
	cout << "\n Ma so:" << maso;
	cout << "\n So luong chi tiet thanh phan: " << n;
	for (int i = 0; i < n; i++)
	{
		ds[i]->Xuat();
	}
}

float CChiTietPhuc::TinhTien()
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + ds[i]->TinhTien();
	return s;
}

CChiTiet* CChiTietPhuc::TimKiem(long ms)
{
	if (maso == ms)
		return this;
	for (int i = 0; i < n; i++)
	{
		CChiTiet* kq = ds[i]->TimKiem(ms);
		if (kq != NULL)
			return kq;
	}
	return NULL;
}

int CChiTietPhuc::DemChiTietDon()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		dem = dem + ds[i]->DemChiTietDon();
	return dem;
}

