//
// Created by tung on 09/06/2022.
//

#include "SeperatedTicket.h"

SeperatedTicket::SeperatedTicket()
{
    priceEachGame = 20000;
    priceTicket = 70000;
}

SeperatedTicket::~SeperatedTicket()
{
    return;
}

void SeperatedTicket::Read()
{
    Ticket::Read();
    cout <<"\nEnter the number of games: ";
    cin >> priceEachGame;
}
void SeperatedTicket::Print()
{
    Ticket::Print();
    cout <<"\nNumber of games: "<<numberOfGames;
}

int SeperatedTicket::GetPriceTicket()const
{
    return priceTicket + priceEachGame*numberOfGames;
}

int SeperatedTicket::Count()const
{
    return 1;
}

int SeperatedTicket::CheckType()const
{
    return Type::SEPERATED_TICKET;
}