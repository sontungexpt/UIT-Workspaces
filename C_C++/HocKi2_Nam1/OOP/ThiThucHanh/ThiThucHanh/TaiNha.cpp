#include "TaiNha.h"


TaiNha::TaiNha()
{
	SubPrice = 50000;
	Key = 3;
}

TaiNha::~TaiNha()
{
	return;
}
int TaiNha::GetKms()
{
	return NumberOfKms;
}

int TaiNha::GetPrice()
{
	if (NumberOfKms > 3)
		NumberOfKms = NumberOfKms - 3;
	else
		NumberOfKms = 0;
	return PriceOfEachTable * NumberOfTables + PriceOfEachBeerCan * NumberOfBeerCans + NumberOfKms * SubPrice;
}

void TaiNha::Print()
{
	Service::Print();
	cout << "\nSo gio da dat: " << NumberOfTables;
	cout << "\nSo lon bia da su dung: " << NumberOfBeerCans;
	cout << "\nSo km da vuot qua: ";
}

void TaiNha::Read()
{
	Service::Read();
	cout << "Nhap so gio ban muon dat: ";
	cin >> NumberOfTables;
	cout << "Nhap so lon bia da su dung: ";
	cin >> NumberOfBeerCans;
	cout << "Nhap so km: ";
	cin >> NumberOfKms;
}