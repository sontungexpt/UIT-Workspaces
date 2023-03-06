#include <iostream>
#include <string>
using namespace std;

class Student
{
private: 
	string fullName;
	int math;
	int literature;

public:
	void Input();
	void Print();
	float GetAverage();
};


int main()
{
	Student hs;
	hs.Input();
	hs.Print();
	return 0;
}
void Student::Input()
{
	cout << "Nhap ten: ";
	getline(cin, fullName);
	cout << "Nhap toan: ";
	cin >> math;
	cout << "Nhap van: ";
	cin >> literature;
}

float Student::GetAverage()
{
	return (float)(math + literature) / 2;
}

void Student::Print()
{
	cout << "\nHo ten: " << fullName;
	cout << "\nToan: " << math;
	cout << "\nVan: " << literature;
	cout << "\nDTB: " << GetAverage();
}