#pragma once
#include "Service.h"

class DatBan : public Service
{
private:
	int PriceOfEachTable;

	int NumberOfTables;

	int PriceOfEachBeerCan;

	int NumberOfBeerCans;


public:
	DatBan();

	~DatBan();
	void Print();
	void Read();
	int GetPrice();

};

