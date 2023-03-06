//
// Created by tung on 09/06/2022.
//

#include "DamSenPark.h"

DamSenPark::DamSenPark()
{
    numTickets = 0;
    tickets = nullptr;
}
DamSenPark::~DamSenPark()
{

    if (tickets != nullptr)
    {
        delete[] tickets;
        tickets = nullptr;
    }
    numTickets = 0;
}
void DamSenPark::Read()
{
    do
    {
        cout << "\nEnter the number of tickets: ";
        cin >> numTickets;
    } while (numTickets < 0);

    tickets = new Ticket *[numTickets];

    int key;
    for (int i = 0; i < numTickets; i++)
    {
        do
        {
            cout << "\nEnter the type of tickets ("
                 << Ticket::Type::FULL_TICKET << ".Full tickets, "
                 << Ticket::Type::SEPERATED_TICKET << ". Seperated tickets): ";
            cin >> key;
        } while (key != Ticket::Type::FULL_TICKET and key != Ticket::Type::SEPERATED_TICKET);
        switch (key)
        {
        case Ticket::Type::FULL_TICKET:
            tickets[i] = new FullTicket;
            break;
        case Ticket::Type::SEPERATED_TICKET:
            tickets[i] = new SeperatedTicket;
            break;
        default:
            break;
        }
        tickets[i]->Read();
    }
}
void DamSenPark::Print()
{
    for (int i = 0; i < numTickets; i++)
    {
        tickets[i]->Print();
    }
}
// return the sum of prices tickets of a day
int DamSenPark::Profit()
{
    int sum = 0;
    for (int i = 0; i < numTickets; i++)
    {
        sum += tickets[i]->GetPriceTicket();
    }
    return sum;
}
int DamSenPark::CountSeparatedTickets()
{
    int count = 0;
    for (int i = 0; i < numTickets; i++)
    {
        // Solution 1
        if (dynamic_cast<SeperatedTicket *>(tickets[i]) != nullptr)
            count += tickets[i]->Count();
    }
    return count;
}
