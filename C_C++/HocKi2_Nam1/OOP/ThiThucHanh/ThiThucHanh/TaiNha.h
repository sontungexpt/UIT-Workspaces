#pragma once
#include "Service.h"
class TaiNha :public Service
{
private:
	int PriceOfEachTable;

	int NumberOfTables;

	int PriceOfEachBeerCan;

	int NumberOfBeerCans;

	int NumberOfKms;

	int SubPrice;


public:

	TaiNha();

	~TaiNha();
	int GetKms();
	int GetPrice();

	void Print();

	void Read();
};

