#include "CMay.h"
#include"CChiTietDon.h"
#include"CChiTietPhuc.h"
#include<iostream>
using namespace std;

void CMay::Nhap()
{
	cout << "Nhap so luong chi tiet cua may: ";
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

void CMay::Xuat()
{
	cout << "\nSo luong chi tiet thanh phan: " << n;
	for (int i = 0; i < n; i++)
	{
		ds[i]->Xuat();
	}
}

float CMay::TinhTien()
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + ds[i]->TinhTien();
	return s;
}

CChiTiet* CMay::TimKiem(long ms)
{
	for (int i = 0; i < n; i++)
	{
		CChiTiet* kq = ds[i]->TimKiem(ms);
		if (kq != NULL)
			return kq;
	}
	return NULL;
}

int CMay::DemChiTietDon()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		dem = dem + ds[i]->DemChiTietDon();
	return dem;
}
