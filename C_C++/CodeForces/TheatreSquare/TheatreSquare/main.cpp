#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	int m;
	int a;
	int number_of_flagstones = 0;
	do
		cin >> n;
	while (n < 1 and n > pow(10, 9));

	do
		cin >> m;
	while (m < 1 and m > pow(10, 9));

	do
		cin >> a;
	while (a < 1 and a > pow(10, 9));

	number_of_flagstones = ceil((double)m / a) * ceil((double)n / a);

	cout << number_of_flagstones;

}