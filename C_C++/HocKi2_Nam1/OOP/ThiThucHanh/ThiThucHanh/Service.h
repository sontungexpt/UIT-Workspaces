#pragma once
#include <iostream>
#include <string>
using namespace std;


class Service
{
protected:
	string FullName;
	string PhoneNumber;
	int Key;

public:
	Service();

	virtual ~Service();

	void setFullName(string);
	void setPhoneNumber(string);
	string getFullName();
	string getPhoneNumber();
	int GetKey();
	virtual int GetPrice();
	virtual void Read();
	virtual void Print();
};

