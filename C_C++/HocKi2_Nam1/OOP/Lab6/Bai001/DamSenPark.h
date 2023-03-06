//
// Created by tung on 09/06/2022.
//

#ifndef _LAB6_DAMSENPARK_H
#define _LAB6_DAMSENPARK_H
#include "SeperatedTicket.h"
#include "FullTicket.h"
class DamSenPark
{
private:
    Ticket **tickets;
    int numTickets;

public:

    DamSenPark();

    ~DamSenPark();

    void Read();

    void Print();

    //return the sum of prices tickets of a day
    int Profit();

    int CountSeparatedTickets();


};


#endif //!_LAB6_DAMSENPARK_H
