//
// Created by tung on 09/06/2022.
//

#include "FullTicket.h"

FullTicket::FullTicket():Ticket()
{
    priceTicket = 200000;
}

FullTicket::~FullTicket()
{
    return;
}

void FullTicket::Print()
{
    FullTicket::Print();
}

void FullTicket::Read()
{
    Ticket::Read();
}

int FullTicket::GetPriceTicket()const
{
    return priceTicket;
}

int FullTicket::Count()const
{
    return 1;
}

int FullTicket::CheckType()const
{
    return Type::FULL_TICKET;
}
