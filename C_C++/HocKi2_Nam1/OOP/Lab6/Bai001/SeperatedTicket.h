//
// Created by tung on 09/06/2022.
//

#ifndef LAB6_SeperatedTicket_H
#define LAB6_SeperatedTicket_H
#include "Ticket.h"

class SeperatedTicket:public Ticket{
private:
    int priceEachGame;
    int numberOfGames;

public:
    SeperatedTicket();

    ~SeperatedTicket();

    void Read();

    void Print();

    int GetPriceTicket() const ;

    int Count() const;

    int CheckType()const;
};


#endif //LAB6_SeperatedTicket_H
