//
// Created by tung on 09/06/2022.
//

#ifndef LAB6_TICKET_H
#define LAB6_TICKET_H
#include <iostream>

using namespace std;

#include <string>

class Ticket {

protected:
    string idTicket;
    string fullName;
    int yearOfBirth;
    int priceTicket;

public:

    enum Type
    {
        FULL_TICKET = 1,
        SEPERATED_TICKET,
    };
    Ticket();

    Ticket(const string &, const string &, int);

    Ticket(const Ticket &);

    virtual~Ticket();

    const string &getIdTicket() const;

    const string &getFullName() const;

    int getYearOfBirth() const;

    void setIdTicket(const string &);

    void setFullName(const string &);

    void setYearOfBirth(int);

    virtual void Read() ;

    virtual void Print()const;

    virtual int GetPriceTicket() const;

    virtual int Count()const;

    virtual int CheckType()const;
};

#endif //LAB6_TICKET_H
