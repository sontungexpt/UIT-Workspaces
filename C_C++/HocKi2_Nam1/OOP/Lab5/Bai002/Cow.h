#ifndef _Cow_h
#define _Cow_h
#include "Catle.h"

class Cow: public Catle 
{
#pragma region Feilds 
private:
#pragma endregion

public:
#pragma region Constructor
	Cow();

#pragma endregion

#pragma region Properties

#pragma endregion

#pragma region Method
	void Sound();

	void SetMilkAmount();
#pragma endregion
};


#endif // !_Cow_h


