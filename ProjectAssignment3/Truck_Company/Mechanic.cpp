//
// Created by Jordan Daudu on 04/08/2024.
//
#include "Employee.h"
#include "Mechanic.h"
#include <iostream>
using namespace std;

Mechanic::Mechanic() : Employee() // constructor
{
    overtimeHours = 0;
}
Mechanic::Mechanic(char *name, long id, int seniority, int overtimeHours) : Employee(name, id, seniority) // constructor with parameters
{
    this->overtimeHours = overtimeHours;
}
Mechanic::~Mechanic() // destructor
{
}
int Mechanic::getOvertimeHours() const // getting overtime hours of mechanic
{
    return overtimeHours;
}
char *Mechanic::getType() const // getting class name
{
    return "Mechanic";
}
void Mechanic::print() const // printing parameters
{
    Employee::print();
    cout << "Salary: " << salary() << endl;
}
int Mechanic::salary() const // getting salary of mechanic
{
    return (6000 + (500 * seniority) + (100 * overtimeHours));
}
