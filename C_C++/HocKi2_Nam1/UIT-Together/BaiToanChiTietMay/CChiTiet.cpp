#include "CChiTiet.h"
#include<iostream>
using namespace std;


void CChiTiet::Nhap()
{
	return;
}

void CChiTiet::Xuat()
{
	return;
}

float CChiTiet::TinhTien()
{
	return 0;
}

CChiTiet* CChiTiet::TimKiem(long ms)
{
	if (maso == ms)
		return this;
	return NULL;
}

int CChiTiet::DemChiTietDon()
{
	return 0;
}