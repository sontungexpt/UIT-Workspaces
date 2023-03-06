#include "CTimeSpan.h"

#include "CTimeSpan.h"
#include "CTime.h"

int main()
{
	CTimeSpan a, b;
	cout << "Input CTimeSpan a: \n";
	cin >> a;
	cout << "Input CTimeSpan b: \n";
	cin >> b;

	CTimeSpan cTimeSpanResult;
	cTimeSpanResult = a + b;
	cout << "\na + b = " << cTimeSpanResult;
	cTimeSpanResult = a - b;
	cout << "\na - b = " << cTimeSpanResult;

	if (a == b)
		cout << "\na = b";
	else
		cout << "\na != b";

	if (a != b)
		cout << "\na != b";
	else
		cout << "\na = b";

	if (a > b)
		cout << "\na > b";
	else
		cout << "\na not > b";

	if (a >= b)
		cout << "\na >= b";
	else
		cout << "\na not >= b";

	if (a < b)
		cout << "\na < b";
	else
		cout << "\na not < b";

	if (a <= b)
		cout << "\na <= b";
	else
		cout << "\na not <= b";


	CTime c, d;
	cout << "\n\nInput CTime c: \n";
	cin >> c;
	cout << "Input CTime d: \n";
	cin >> d;
	int second;
	cout << "Input second to caculate: ";
	cin >> second;
	CTime cTimeResult;
	cTimeResult = c + second;
	cout << "\nAfter adding second to c, c = " << cTimeResult;
	cTimeResult = d - second;
	cout << "\nAfter subtration second to d, d = " <<cTimeResult;
	cTimeSpanResult = c - d;
	cout << "\nSpacing of c and d la: " << cTimeSpanResult;
	cTimeResult = c + a;
	cout << "\nc after adding a = " << cTimeResult;
	c++;
	cout << "\nc + 1 second = " << c;
	c--;
	cout << "\nc - 1 second = " << c;

	return 1;
}