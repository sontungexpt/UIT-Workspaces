#include "CMachNoiTiep.h"
#include"CMachSongSong.h"
#include"CDienTro.h"
#include<iostream>
using namespace std;

void CMachNoiTiep::Nhap()
{
	cout << "Nhap n:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai;
		cout << "Nhap loai (0. Noi tiep, 1. Song song, 2. Dien tro):";
		cin >> loai;
		switch (loai)
		{
		case 0: ds[i] = new CMachNoiTiep;
			break;
		case 1: ds[i] = new CMachSongSong;
			break;
		case 2: ds[i] = new CDienTro;
			break;
		}
		ds[i]->Nhap();
	}
}

void CMachNoiTiep::Xuat()
{
	cout << "So luong mach dien thanh phan:";
	cout << n;
	for (int i = 0; i < n; i++)
	{
		ds[i]->Xuat();
	}
}

float CMachNoiTiep::TinhDienTro()
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + ds[i]->TinhDienTro();
	return s;
}
	