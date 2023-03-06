//
// Created by tung on 13/06/2022.
//

#ifndef _LAB6_2_DEVELOPER_H
#define _LAB6_2_DEVELOPER_H

#include "Staff.h"

class Developer : public Staff {
private:
    int Overtime;

public:
    Developer();

    ~Developer();

    void Read();

    void Print() const;

    int GetSalary() const;

};


#endif //!_LAB6_2_DEVELOPER_H
