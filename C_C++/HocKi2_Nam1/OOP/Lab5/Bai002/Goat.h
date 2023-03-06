#ifndef _Goat_h
#define _Goat_h
#include "Catle.h"


class Goat: public Catle
{
#pragma region Feilds 
private:

#pragma endregion

public:
#pragma region Constructor
	Goat();

#pragma endregion

#pragma region Properties

#pragma endregion

#pragma region Method
	void Sound();

	void SetMilkAmount();
#pragma endregion

};

#endif // !_Goat_h

