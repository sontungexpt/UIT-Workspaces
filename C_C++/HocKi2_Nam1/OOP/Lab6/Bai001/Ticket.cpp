//
// Created by tung on 09/06/2022.
//

#include "Ticket.h"

Ticket::Ticket() {
    idTicket = "";
    fullName = "";
    yearOfBirth = 0;
    priceTicket = 0;
}

Ticket::Ticket(const string &idTicket, const string &fullName, int yearOfBirth) {
    this->idTicket = idTicket;
    this->fullName = fullName;
    this->yearOfBirth = yearOfBirth;
}

Ticket::Ticket(const Ticket &ticket) {

}

const string &Ticket::getIdTicket() const {
    return idTicket;
}

const string &Ticket::getFullName() const {
    return fullName;
}

int Ticket::getYearOfBirth() const {
    return yearOfBirth;
}

Ticket::~Ticket() {
    return;
}

void Ticket::setIdTicket(const string &idTicket) {
    Ticket::idTicket = idTicket;
}

void Ticket::setFullName(const string &fullName) {
    Ticket::fullName = fullName;
}

void Ticket::setYearOfBirth(int yearOfBirth) {
    Ticket::yearOfBirth = yearOfBirth;
}

void Ticket::Read() {
    cout << "\n\nEnter the id of the ticket: ";
    cin.ignore();
    getline(cin, idTicket);
    cout << "\nEnter the Customer's full name: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "\nEnter the year of Customer's birthday: ";
    cin >> yearOfBirth;
}

void Ticket::Print() const {
    cout << "\nID ticket: " << idTicket;
    cout << "\nCustomer's full name: " << fullName;
    cout << "\nYear of Customer's birthday: " << yearOfBirth;
    cout << "\nThe sum of ticket's prices: " << GetPriceTicket();
}

int Ticket::GetPriceTicket() const {
    return priceTicket;
}

int Ticket::Count()const
{
    return 0;
}

int Ticket::CheckType() const
{
    return 0;
}