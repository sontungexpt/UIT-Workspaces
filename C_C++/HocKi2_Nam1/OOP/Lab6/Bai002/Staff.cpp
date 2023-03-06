//
// Created by tung on 13/06/2022.
//

#include "Staff.h"

Staff::Staff() {
	ID = "";
	FullName = "";
	Age = 0;
	PhoneNumber = "";
	Email = "";
	BasicSalary = 0;
}

Staff::~Staff() {
	ID = "";
	FullName = "";
	Age = 0;
	PhoneNumber = "";
	Email = "";
	BasicSalary = 0;
}

const string& Staff::getId() const {
	return ID;
}

void Staff::setId(const string& id) {
	ID = id;
}

const string& Staff::getFullName() const {
	return FullName;
}

void Staff::setFullName(const string& fullName) {
	FullName = fullName;
}

int Staff::getAge() const {
	return Age;
}

void Staff::setAge(int age) {
	Age = age;
}

const string& Staff::getPhoneNumber() const {
	return PhoneNumber;
}

void Staff::setPhoneNumber(const string& phoneNumber) {
	PhoneNumber = phoneNumber;
}

const string& Staff::getEmail() const {
	return Email;
}

void Staff::setEmail(const string& email) {
	Email = email;
}

int Staff::getBasicSalary() const {
	return BasicSalary;
}

void Staff::setBasicSalary(int basicSalary) {
	BasicSalary = basicSalary;
}

void Staff::Read() {
	cout << "\nEnter ID of staff: ";
	cin.ignore();
	getline(cin, ID);
	cout << "\nEnter the full name of staff: ";
	getline(cin, ID);
	cout << "\nEnter the age of staff: ";
	cin >> Age;
	cout << "\nEnter phone number of staff: ";
	cin.ignore();
	getline(cin, PhoneNumber);
	cout << "\nEnter the email of staff: ";
	getline(cin, Email);
	cout << "\nEnter the basic salary of staff: ";
	cin >> BasicSalary;
}

void Staff::Print() const {
	cout << "\nID: " << ID;
	cout << "\nFull name: " << FullName;
	cout << "\nAge: " << Age;
	cout << "\nPhone number: " << PhoneNumber;
	cout << "\nEmail: " << Email;
	cout << "\nBasic salary: " << BasicSalary << " d";
	cout << "\nSalary: " << GetSalary() << " d";
}