#pragma once
#include"CMachDien.h"
#include<iostream>
using namespace std;

class CMachSongSong :public CMachDien
{
protected:
	int n;
	CMachDien * ds[100];
public:
	void Nhap();
	void Xuat();
	float TinhDienTro();
};
