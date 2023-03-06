#include "Time.h"

int main()
{
	Time A;
	cout << "\nNhap thoi gian A:\n";
	cin >> A;
	cout << "\nThoi gian A:\n";
	cout << A;
	cout << "\nThoi gian ke tiep cua A: \n";
	A.FindNextTime().Print();
	cout << "\nThoi gian truoc do cua A: \n";
	A.FindPreviousTime().Print();
	Time B;
	cout << "\nNhap thoi gian B: \n";
	cin >> B;
	cout <<"\nThoi gian B: \n"<<B;
	if (A.Compare(B) == -1)
		cout << "\nA<B";
	else if (A.Compare(B) == 1)
		cout << "\nA=B";
	else
		cout << "\nA>B";

	return 0;
}