#include "CThuMuc.h"
#include"CLuuTru.h"
#include"CTapTin.h"
#include<iostream>
using namespace std;

void CThuMuc::Nhap()
{
	cout << "Nhap so doi tuong luu tru: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai;
		cout << "Nhap loai doi tuong luu tru (0. Tap tin, 1. Thu muc): ";
		cin >> loai;
		switch (loai)
		{
		case 0: ds[i] = new CTapTin;
			break;
		case 1: ds[i] = new CThuMuc;
			break;
		}
		ds[i]->Nhap();
	}
}

void CThuMuc::Xuat()
{
	for (int i = 0; i < n; i++)
		ds[i]->Xuat();
}

float CThuMuc::TinhDungLuong()
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s=s + ds[i]->TinhDungLuong();
	return s;
}

int CThuMuc::DemTapTin()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		dem = dem + ds[i]->DemTapTin();
	return dem;
}

int CThuMuc::DemThuMuc()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		dem = dem + ds[i]->DemThuMuc();
	return dem;
}
