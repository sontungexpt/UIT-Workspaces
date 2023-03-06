#ifndef _Tank_h
#define _Tank_h
#include "Controller.h"

class Tank
{
private:
	Controller controller;

public:
	Tank();
	~Tank();
	void BootTheSystem();
	
};

#endif // !_Tank_h

