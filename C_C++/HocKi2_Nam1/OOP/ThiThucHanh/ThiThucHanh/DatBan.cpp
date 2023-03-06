#include "DatBan.h"


DatBan::DatBan()
{
	PriceOfEachTable = 2000000;
	PriceOfEachBeerCan = 16000;
	Key = 1;
}

DatBan::~DatBan()
{
	return;
}

int DatBan::GetPrice()
{
	return PriceOfEachTable * NumberOfTables + PriceOfEachBeerCan * NumberOfBeerCans;
}

void DatBan::Print()
{
	Service::Print();
	cout << "\nSo gio da dat: " << NumberOfTables;
	cout << "\nSo lon bia da su dung: " << NumberOfBeerCans;
	//cout << "Gia cua dich vu la: " << GetPrice();
}
void DatBan::Read()
{
	Service::Read();
	cout << "Nhap so gio ban muon dat: ";
	cin >> NumberOfTables;
	cout << "Nhap so lon bia da su dung: ";
	cin >> NumberOfBeerCans;
}