#include "Restaurant.h"


int main()
{
	Restaurant a;
	a.Read();
	a.Print();
	cout << " tong " << a.GetSumOfPrice();
	cout << a.FindMax();
	//a.GetAverageKm();
	return 0;
}