//
// Created by tung on 09/06/2022.
//

#ifndef _LAB6_FULLTICKET_H
#define _LAB6_FULLTICKET_H

#include <iostream>
#include "Ticket.h"

using namespace std;

class FullTicket : public Ticket {

public:

    FullTicket();

    ~FullTicket();

    void Read();

    void Print();

    int GetPriceTicket() const;

    int Count() const;

    int CheckType()const;
};


#endif //!_LAB6_FULLTICKET_H
