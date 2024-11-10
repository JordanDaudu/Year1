#include <iostream>
#include <cstring>
#include "Employee.h"
#include "Delivery.h"
#include "Mechanic.h"
#include "Driver.h"
#include "Director.h"
#define MAX 30
using namespace std;
int Driver::over8000KgDeliveries = 0;
int main()
{
    char name[MAX];
    int numberOfEmployees, numberOfDeliveries;
    int seniority, overtimeHours, distance, weight, type;
    long id;
    bool foundID, foundOvertime = false;
    cout << "~~~~~~~TRUCK COMPANY~~~~~~~\nHow many employees there is in the company? " << endl;
    // getting the number of employees in the company
    cin >> numberOfEmployees;
    Employee **pointer = new Employee*[numberOfEmployees];
    // getting information on all employees
    for(int i = 0; i < numberOfEmployees; i++)
    {
        do
        {
            cout << "||Choose employee " << i+1 << " type||\n1. Mechanic\n2. Driver\n3. Director" << endl;
            cin >> type;
            if(type <= 0 || type > 3)
                cout << "Error! please input a number that is supported, try again." << endl;
        }
        while(type <= 0 || type > 3);
        switch (type)
        {
            case 1:
                // mechanic employee
                cout << "||Mechanic: Input employee " << i+1 << " name, id, seniority and overtime hours (4 parameters): ";
                cin >> name >> id >> seniority >> overtimeHours;
                pointer[i] = new Mechanic(name, id, seniority, overtimeHours);
                break;
            case 2:
            {
                // driver employee
                cout << "||Driver: Input employee " << i+1 << " name, id and seniority (3 parameters): ";
                cin >> name >> id >> seniority;
                cout << "How many deliveries did the driver " << name << " do this month? ";
                cin >> numberOfDeliveries;
                Delivery *arr = new Delivery[numberOfDeliveries];
                for(int j = 0; j < numberOfDeliveries; j++)
                {
                    cout << "~~~Package " << j+1 << "~~~" << endl;
                    do
                    {
                        cout << "Input distance of delivery: ";
                        cin >> distance;
                        cout << "Input weight of delivery: ";
                        cin >> weight;
                        if(distance < 0 || weight < 0)
                            cout << "Input given was negative, please input again" << endl;
                    }
                    while(distance < 0 || weight < 0);
                    arr[j].setDistance(distance);
                    arr[j].setWeight(weight);
                }
                pointer[i] = new Driver(name, id, seniority, arr, numberOfDeliveries);
                break;
            }
            case 3:
                // director employee
                cout << "||Director: Input employee " << i+1 << " name, id and seniority and (3 parameters): ";
                cin >> name >> id >> seniority;
                pointer[i] = new Director(name, id, seniority);
                break;
            default:
                cout << "Error! input not supported" << endl;
                i--;
        }
    }
    //adding a single package to a driver (if id inputted is indeed a driver)
    cout << "Lets add a package, please type the driver id, distance of package and weight (3 parameter): ";
    cin >> id >> distance >> weight;
    Delivery newPackage(distance, weight);
    for(int i = 0; i < numberOfEmployees; i++)
    {
        foundID = false;
        if(pointer[i]->getId() == id)
            if(strcmp(pointer[i]->getType(), "Driver") == 0)
            {
                Driver *driver = dynamic_cast <Driver *>(pointer[i]);
                driver->addPackage(newPackage);
                cout << "\n||Added package successfully||" << endl;
                foundID = true;
                break;
            }
    }
    if(!foundID)
        cout << "\n||Error! couldn't find a matching driver ID, package wasn't added||" << endl;
    //printing all employees name and salary
    cout << "\n~~~~~All employees information~~~~~" << endl;
    for(int i = 0; i < numberOfEmployees; i++)
    {
        cout << "||Employee " << i+1 << "||" << endl;
        pointer[i]->print();
        cout << endl;
    }
    //printing number of deliveries that are over 8000kg
    cout << "Number of deliveries that were over 8000 kg: ";
    Driver::printStatic();
    //printing mechanics that worked overtime
    cout << "\n~~~Mechanics that worked overtime hours~~~" << endl;
    for(int i = 0; i < numberOfEmployees; i++)
    {
        if(strcmp(pointer[i]->getType(), "Mechanic") == 0)
        {
            Mechanic *mechanic = dynamic_cast<Mechanic *>(pointer[i]);
            if(mechanic->getOvertimeHours() != 0)
            {
                cout << pointer[i]->getName() << endl;
                foundOvertime = true;
            }
        }
    }
    if(!foundOvertime)
        cout << "None of the mechanics worked overtime" << endl;
    //deleting memory properly that hasn't been deleted already from classes
    for(int i = 0; i < numberOfEmployees; i++)
        delete pointer[i];
    delete[] pointer;
    return 0;
}