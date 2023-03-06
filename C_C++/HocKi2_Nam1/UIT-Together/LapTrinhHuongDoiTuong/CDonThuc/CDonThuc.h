#pragma once
#include <iostream>
using namespace std;

class CDonThuc
{
private: 
	float a;
	int n;
	CDonThuc Derivatives();

public:
	//constructor 
	CDonThuc();
	CDonThuc(float, int);
	CDonThuc(const CDonThuc &);

	//destructor 
	~CDonThuc();

	//method
	void Input();
	void Print();
	CDonThuc Nhan(CDonThuc);
	CDonThuc Chia(CDonThuc);
	CDonThuc Derivatives(int);
	float GetValue(float);
	
	friend istream& operator >> (istream&, CDonThuc&);
	friend ostream& operator << (ostream&, CDonThuc&);
};

