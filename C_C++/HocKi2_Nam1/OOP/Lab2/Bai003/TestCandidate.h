#include "Candidate.h"

class TestCandidate
{
private: 
	int numberOfCandidate = 0;
	Candidate* listCandidate;

public: 
	TestCandidate(int numberOfCandidate = 0 , Candidate *listCandidate = nullptr)
	{
		this->numberOfCandidate = numberOfCandidate;
		this->listCandidate = listCandidate;
	}

	~TestCandidate()
	{
		delete[]listCandidate;
	}

	int GetNumberOfCandidate();
	void SetNumberOfCandidate(int);
	void Input();
	void Print();
};

