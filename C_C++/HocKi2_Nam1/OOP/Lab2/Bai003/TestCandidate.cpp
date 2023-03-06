#include "TestCandidate.h"


int TestCandidate::GetNumberOfCandidate()
{
	return numberOfCandidate;
}
void TestCandidate::SetNumberOfCandidate(int value)
{
	if (value > 0)
		this->numberOfCandidate = value;
	else
		this->numberOfCandidate = 0;
}

void TestCandidate::Input()
{
	do
	{
		cout << "Input number of candidate: ";
		cin >> numberOfCandidate;
	} while (numberOfCandidate < 0);
	listCandidate = new Candidate[numberOfCandidate];
	for (int i = 0; i < numberOfCandidate; i++)
	{
		cout << "\n----------Candidate " << i + 1 << "----------"<<endl;
		listCandidate[i].Input();
		cout << endl;
	}
}
void TestCandidate::Print()
{
	if (numberOfCandidate == 0)
	{
		cout << "Do not have any data on Candidate";
		return;
	}
	cout << "The candidate with a sum of score greater than 15 is:";
	for (int i = 0; i < numberOfCandidate; i++)
		if (listCandidate[i].SumScore() > 15)
		{
			cout << "\n\n----------Candidate " << i + 1 << "----------" << endl;
			listCandidate[i].Print();
		}
}