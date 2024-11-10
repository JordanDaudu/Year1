//
// Created by Jordan Daudu on 04/08/2024.
//

#include "Director.h"
#include <iostream>
using namespace std;

Director::Director() : Employee() // constructor
{
}
Director::Director(char *name, long id, int seniority) : Employee(name, id, seniority) // constructor with parameters
{
}
Director::~Director() // destructor
{}
char *Director::getType() const // getting class name
{
    return "Director";
}
void Director::print() const // printing parameters
{
    Employee::print();
    cout << "Salary: " << salary() << endl;
}
int Director::salary() const // getting salary of director
{
    return (14000 + (1000 * seniority));
}
