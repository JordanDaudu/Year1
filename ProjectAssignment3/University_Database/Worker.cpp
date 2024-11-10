//
// Created by Jordan Daudu on 05/08/2024.
//

#include "Worker.h"
#include <cstring>
#include <iostream>
using namespace std;

Worker::Worker() // constructor
{
    name = nullptr;
    seniority = 0;
}
Worker::Worker(char *name, int seniority) // constructor with parameters
{
    char *newName = new char[strlen(name)];
    strcpy(newName, name);
    this->name = newName;
    this->seniority = seniority;
}

Worker::~Worker() // destructor
{
    delete[] name;
}

char *Worker::getName() const // getting name
{
    return name;
}

long Worker::salary() const // getting salary of normal worker
{
    return (6000 + (400 * seniority));
}

char *Worker::getType() const // getting class name
{
    return "Worker";
}