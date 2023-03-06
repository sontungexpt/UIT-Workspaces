#ifndef _SmartTank_h
#define _SmartTank_h

#include "Controller.h"
#include <conio.h>

class SmartTank
{
private:
	Controller controller;

public:
	SmartTank();
	~SmartTank();
	void BootTheSystem();
	
};

#endif // !_SmartTank_h

