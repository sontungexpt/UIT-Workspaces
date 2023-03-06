#include "Staff.h"


#pragma region Constructor
	Staff::Staff();
	Staff::Staff(string fullName, Date birthDay, int basicWage);
	Staff::Staff(const Staff&);
	
#pragma endregion

#pragma region Properties
	int Staff::GetWage()
    {
        return wage;
    }
	void Staff::SetWage(int value)
    {
        wage = value;
    }
#pragma endregion
	
#pragma region Method

	void Staff::Input();
	void Staff::Print();
	void Staff::CalcWage();
	//virtual Staff* FindStaff();
#pragma endregion
