//
// Created by Jordan Daudu on 04/08/2024.
//

#include "Driver.h"
#include <iostream>
using namespace std;

Driver::Driver() : Employee() // constructor
{
    numberOfDeliveries = 0;
    packages = nullptr;
}
Driver::Driver(char *name, long id, int seniority, Delivery *arr, int size) : Employee(name, id, seniority) // constructor with parameters
{
    packages = arr;
    numberOfDeliveries = size;
    for(int i = 0; i < numberOfDeliveries; i++)
        if(packages[i].getWeight() > 8000)
            over8000KgDeliveries++;
}
Driver::~Driver() // destructor
{
    for(int i = 0; i < numberOfDeliveries; i++)
        if(packages[i].getWeight() > 8000)
            over8000KgDeliveries--;
    delete[] packages;
}
void Driver::addPackage(const Delivery arr) // adding a package to driver
{
    Delivery *newarr = new Delivery[numberOfDeliveries+1];
    for(int i = 0; i < numberOfDeliveries; i++)
        newarr[i] = packages[i];
    delete[] packages;
    newarr[numberOfDeliveries] = arr;
    numberOfDeliveries++;
    if(arr.getWeight() > 8000)
        over8000KgDeliveries++;
    packages = newarr;
}
char *Driver::getType() const // getting class name
{
    return "Driver";
}
void Driver::print() const // printing parameters
{
    Employee::print();
    cout << "Salary: " << salary() << endl;
}
void Driver::printStatic() // printing static
{
    cout << over8000KgDeliveries << endl;
}
int Driver::salary() const // getting salary of driver
{
    int salary = (300 * seniority);
    for(int i = 0; i < numberOfDeliveries; i++)
    {
        salary = salary + 100 + (2 * packages[i].getDistance());
        if(packages[i].getWeight() > 8000)
            if(seniority >= 3)
                salary += 200;
    }
    return salary;
}
