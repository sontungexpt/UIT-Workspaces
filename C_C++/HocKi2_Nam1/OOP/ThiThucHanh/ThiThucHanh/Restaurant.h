#pragma once
#include "Service.h"
#include "DatBan.h"
#include "MuonMatBang.h"
#include "TaiNha.h"

#define MAX 1000

class Restaurant
{
private:
	Service* services[MAX];
	int n;
public:

	Restaurant();
	~Restaurant();
	void Print();
	void Read();

	int GetSumOfPrice();
	int FindMax();
	//int GetAverageKm();
};

