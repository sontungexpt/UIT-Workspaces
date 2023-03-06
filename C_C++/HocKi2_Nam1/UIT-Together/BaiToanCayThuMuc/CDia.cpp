#include "CDia.h"
#include"CTapTin.h"
#include"CThuMuc.h"
#include<iostream>
using namespace std;

void CDia::Nhap()
{
	cout << "Nhap doi tuong luu tru thanh phan: ";
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

void CDia::Xuat()
{
	for (int i = 0; i < n; i++)
		ds[i]->Xuat();
}

float CDia::TinhDungLuong()
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + ds[i]->TinhDungLuong();
	return s;
}

int CDia::DemTapTin()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		dem = dem + ds[i]->DemTapTin();
	return dem;
}

int CDia::DemThuMuc()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		dem = dem + ds[i]->DemThuMuc();
		return dem;
	}
}

