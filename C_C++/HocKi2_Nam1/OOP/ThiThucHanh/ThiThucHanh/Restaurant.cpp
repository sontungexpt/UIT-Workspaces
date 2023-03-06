#include "Restaurant.h"

Restaurant::Restaurant()
{
	n = 0;
}
Restaurant::~Restaurant()
{
	return;
}
void Restaurant::Print()
{
	for (int i = 0; i < n; i++)
		services[i]->Print();
}
void Restaurant::Read()
{
	cout << "\nNhap so luong dich vu: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int key;
	NhapLai:
		cout << "\nNhap dich vu ban chon: (1. Dat Ban, 2. Muon mat bang,3. Tai nha): ";
		cin >> key;
		switch (key)
		{
		case 1:
			services[i] = new DatBan;
			break;
		case 2:
			services[i] = new MuonMatBang;
			break;
		case 3:
			services[i] = new TaiNha;
			break;
		default:
			goto NhapLai;
			break;
		}
		services[i]->Read();
	}
}

int Restaurant::GetSumOfPrice()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += services[i]->GetPrice();
	return sum;
}

int Restaurant::FindMax()
{
	int datban = 0;
	int muonmatbang = 0;
	int tainha = 0;
	for (int i = 0; i < n; i++)
		if (services[i]->GetKey() == 1)
			datban++;
		else if (services[i]->GetKey() == 2)
			muonmatbang++;
		else
			tainha++;
	if (datban > muonmatbang && datban > tainha)
		return 1;
	if (muonmatbang > datban && muonmatbang > tainha)
		return 2;
	if (tainha > muonmatbang && tainha > datban)
		return 3;
}
//int Restaurant::GetAverageKm()
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//		if (services[i]->GetKey() == 3)
//			sum += services[i].ge
//
//}