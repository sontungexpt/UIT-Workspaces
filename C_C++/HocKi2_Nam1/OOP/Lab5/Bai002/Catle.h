#ifndef _Catle_h
#define _Catle_h

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define MAX_CHILD 1000

class Catle
{
#pragma region Feilds 

protected: 
	int milkAmount;
	int childAmount;
	string sound;
	
public:
#pragma endregion
	Catle();
	
#pragma region Constructor

#pragma region Destructor
	~Catle();
#pragma endregion

#pragma endregion

#pragma region Properties
	int GetChildAmount();
	void SetChildAmount(int);

	int GetMilkAmount();
	void SetMilkAmount(int);

	string GetSound();
	void SetSound(string);
#pragma endregion
	
#pragma region Method
	void SetChildAmount();
	int GetLastAmount();
	virtual void Sound();
	virtual void SetMilkAmount();
#pragma endregion

};

#endif // !_Catle_h






