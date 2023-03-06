#include "MuonMatBang.h"


MuonMatBang::MuonMatBang()
{
	PriceOfEachHour = 5000000;
	Key = 2;
}

MuonMatBang::~MuonMatBang()
{
	return;
}

int MuonMatBang::GetPrice()
{
	return PriceOfEachHour * HoursUsed;
}

void MuonMatBang::Read()
{
	Service::Read();
	cout << "Nhap so gio muon dat: ";
	cin >> HoursUsed;
}
void MuonMatBang::Print()
{
	Service::Print();
	cout << "\nSo gio da dat: " << HoursUsed;
}