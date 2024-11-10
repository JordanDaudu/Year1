//
// Created by Jordan Daudu on 04/08/2024.
//

#include "Employee.h"
#include <cstring>
#include <iostream>
using namespace std;

Employee::Employee() // constructor
{
    name = nullptr;
    id = 0;
    seniority = 0;
}
Employee::Employee(char *name, long id, int seniority) // constructor with parameters
{
    char *givenName = new char[strlen(name)];
    strcpy(givenName, name);
    this->name = givenName;
    this->id = id;
    this->seniority = seniority;
}
Employee::~Employee() // destructor
{
    delete[] name;
}

char *Employee::getName() const // getting name of employee
{
    return name;
}
long Employee::getId() const // getting id of employee
{
    return id;
}
int Employee::getSeniority() const // getting seniority of employee
{
    return seniority;
}

void Employee::print() const // printing name of employee
{
    cout << "Name: " << name << endl;
}
