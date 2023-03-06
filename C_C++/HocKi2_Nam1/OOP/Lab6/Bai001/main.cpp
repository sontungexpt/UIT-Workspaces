#include "DamSenPark.h"

int main() {

    DamSenPark park;
    cout <<"------------The tickets manager------------";
    park.Read();
    cout <<"\n------------The tickets information------------";
    park.Print();
    cout <<"\nThe sum of money that the park get after a day is: "<<park.Profit();
    cout <<"\nThe number of seperated tickets are sold out is: "<<park.CountSeparatedTickets();

	return 0;
}
