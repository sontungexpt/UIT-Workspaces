#pragma once
#include "Service.h"
class MuonMatBang : public Service
{
private:

	int HoursUsed;
	int PriceOfEachHour;

public:
	MuonMatBang();

	~MuonMatBang();

	void Read();
	void Print();
	int GetPrice();
};

