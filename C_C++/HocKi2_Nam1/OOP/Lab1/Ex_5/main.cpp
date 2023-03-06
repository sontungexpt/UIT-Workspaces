#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define MAX 100

struct Student {
	string fullName;
	float mathScore;
	float literatureScore;

	Student() {};
	Student(string fullName, float mathScore, float literatureScore)
	{
		this->fullName = fullName;
		this->mathScore = mathScore;
		this->literatureScore = literatureScore;
	}
};
typedef struct Student Student;

void PrintInfo(Student student);
void InputInfo(Student& student);
float CalcAverage(float sub1, float sub2);

int main()
{
	Student student;
	InputInfo(student);
	PrintInfo(student);
	
}
float CalcAverage(float sub1, float sub2)
{
	return (sub1 + sub2) / 2;
}
void InputInfo(Student& student)
{
	cout << "Full Name: ";
	getline(cin,student.fullName);
	cout << "Math Score: ";
	cin >> student.mathScore;
	cout << "Literature Score: ";
	cin >> student.literatureScore;
}
void PrintInfo(Student student)
{
	cout << "---------------------------------------" << endl;
	cout << "Full Name: " << student.fullName << endl;
	cout << "Math Score: " << student.mathScore << endl;
	cout << "Literature Score: " << student.literatureScore << endl;
	cout << "Average Score: " << CalcAverage(student.mathScore, student.literatureScore);
}