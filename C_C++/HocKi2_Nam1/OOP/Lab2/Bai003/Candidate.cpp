#include "Candidate.h"

void Candidate::Input()
{
	cout << "Input index: ";
	cin >> index;
	cout << "Input name: ";
	getline(cin, name, '\n');
	cin.ignore();
	cout << "Input BirthDay\n";
	cout << "Day: ";
	cin >> birth.day;
	cout << "Month: ";
	cin >> birth.month;
	cout << "Year: ";
	cin >> birth.year;
	cout << "Input math score: ";
	cin >> mathScore;
	cout << "Input literature score: ";
	cin >> literatureScore;
	cout << "Input english score: ";
	cin >> englishScore;
}

void Candidate::Print()
{
	cout << "Index: " << index << endl;
	cout << "Name: " << name << endl;
	cout << "Birth day: " << birth.day << "/" << birth.month << "/" << birth.year << endl;
	cout << "Math score: " << mathScore << endl;
	cout << "Literature score: " << literatureScore<<endl;
	cout << "English score: " << englishScore << endl;
}
float Candidate::SumScore()
{
	return mathScore + literatureScore + englishScore;
}