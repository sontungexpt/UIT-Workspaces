#include "Catle.h"

#pragma endregion
Catle::Catle()
{
	this->childAmount = 0;
	this->milkAmount = 0;
	this->sound = "uhm";
}
#pragma region Constructor

#pragma region Destructor
Catle::~Catle()
{
	return;
}
#pragma endregion


#pragma region Properties
int Catle::GetChildAmount()
{
	return this->childAmount;
}
void Catle::SetChildAmount(int value)
{
	this->childAmount = value;
}

int Catle::GetMilkAmount()
{
	return this->milkAmount;
}
void Catle::SetMilkAmount(int value)
{
	this->milkAmount = value;
}
string Catle::GetSound()
{
	return this->sound;
}

void Catle::SetSound(string value)
{
	this->sound = value;
}
#pragma endregion

#pragma region Method
void Catle::Sound()
{
	return;
}


void Catle::SetChildAmount()
{
	this->childAmount = rand() % (4 - 1 + 1) + 1;
}

void Catle::SetMilkAmount()
{
	return;
}

//lấy tổng số lượng của mẹ và con
int Catle::GetLastAmount()
{
	srand(time(NULL));
	this->SetChildAmount();
	return (1 + this->GetChildAmount());
}


#pragma endregion
