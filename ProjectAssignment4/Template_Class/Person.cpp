//
// Created by Jordan Daudu on 21/08/2024.
//

#include "Person.h"
#include <cstring>

Person::Person()
{
    name = nullptr;
    id = 0;
}
Person::Person(char *n, long id)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    this->id = id;
}
Person::Person(const Person &p)
{
    name = nullptr;
    if(p.name != nullptr)
    {
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }
    id = p.id;
}
Person::~Person()
{
    delete[] name;
}

void Person::setParameters(char *n, long idInput)
{
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    id = idInput;
}
Person &Person::operator=(const Person &p)
{
    if(this != &p)
    {
        id = p.id;
        delete[] name;
        name = nullptr;
        if(p.name != nullptr)
        {
            name = new char[strlen(p.name) + 1];
            strcpy(name, p.name);
        }
    }
    return *this;
}

bool Person::operator==(const Person &p) const
{
    return (id == p.id && strcmp(name, p.name) == 0);
}

ostream &operator<<(ostream &os, const Person &p)
{
    os << "(Name: " << p.name << ", ID: " << p.id << ")" << endl;
    return os;
}