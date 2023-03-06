#include <iostream>
using namespace std;

class CSoPhuc
{
private:
	float realEle;
	float virtualEle;
public:
	//constuctor
	CSoPhuc();
	CSoPhuc(float realEle, float virtualEle);
	CSoPhuc(const CSoPhuc&);

	//destructor
	~CSoPhuc();

	//properties
	float GetRealEle();
	void SetRealEle(float);
	float GetVirtualEle();
	void SetVirtualEle(float);
	float Module();
	//method
	friend istream& operator >>(istream&, CSoPhuc&);
	friend ostream& operator <<(ostream&, CSoPhuc&);
	void Input();
	void Print();
	
	CSoPhuc operator +(CSoPhuc);
	CSoPhuc operator -(CSoPhuc);
	CSoPhuc operator *(CSoPhuc);
	CSoPhuc operator /(CSoPhuc);

	bool  operator > (CSoPhuc);
	bool  operator < (CSoPhuc);
	bool operator == (CSoPhuc);
	bool  operator != (CSoPhuc);
	bool  operator >= (CSoPhuc);
	bool  operator <= (CSoPhuc);
};

