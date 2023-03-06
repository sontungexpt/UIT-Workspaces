//
// Created by tung on 13/06/2022.
//

#ifndef _LAB6_2_STAFF_H
#define _LAB6_2_STAFF_H

#include <iostream>
#include <string>

using namespace std;

class Staff {

protected:
    string ID;
    string FullName;
    int Age;
    string PhoneNumber;
    string Email;
    int BasicSalary;

public:
    enum Type {
        DEVELOPER = 1,
        TESTER,
    };

    Staff();

    virtual ~Staff();

    const string &getId() const;

    void setId(const string &id);

    const string &getFullName() const;

    void setFullName(const string &fullName);

    int getAge() const;

    void setAge(int age);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    const string &getEmail() const;

    void setEmail(const string &email);

    int getBasicSalary() const;

    void setBasicSalary(int basicSalary);

    virtual void Read();

    virtual void Print() const;

    virtual int GetSalary() const = 0;
};


#endif //!_LAB6_2_STAFF_H
