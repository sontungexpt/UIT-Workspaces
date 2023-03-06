//
// Created by tung on 13/06/2022.
//

#ifndef _LAB6_2_TESTER_H
#define _LAB6_2_TESTER_H

#include "Staff.h"

class Tester :public Staff {

private:
    int NumberOfBugs;

public:
    Tester();

    ~Tester();

    void Read();

    void Print()const;

    int GetSalary()const;

};


#endif //!_LAB6_2_TESTER_H
