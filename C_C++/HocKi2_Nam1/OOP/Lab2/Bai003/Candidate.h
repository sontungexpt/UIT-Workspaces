#include <iostream>
#include <string>

using namespace std;

struct Birth
{
	int day = 1;
	int month = 1;
	int year = 1;
};
typedef struct Birth Birth;

class Candidate
{
private:
	//feilds;
	string name;
	int index;
	int mathScore;
	int literatureScore;
	int englishScore;
	Birth birth = {1,1,1};

public:
	//constructor
	Candidate() {};
	//method
	void Input();
	void Print();
	float SumScore();
};

