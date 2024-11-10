//
// Created by Jordan Daudu on 05/08/2024.
//

#include "Course.h"
#include <cstring>
#define MAX 20
Course::Course() // constructor
{
    name = nullptr;
    weeklyHours = 0;
    numberOfStudents = 0;
}
Course::Course(char *name, int weeklyHours, int numberOfStudents) // constructor with parameters
{
    char *newName = new char[strlen(name)];
    strcpy(newName, name);
    this->name = newName;
    this->weeklyHours = weeklyHours;
    this->numberOfStudents = numberOfStudents;
}

Course::~Course() // destructor
{
    delete[] name;
}

char *Course::getName() const // getting name of course
{
    return name;
}

int Course::getWeeklyHours() const // getting weekly hours of course
{
    return weeklyHours;
}
int Course::getNumberOfStudents() const // getting number of students in the course
{
    return numberOfStudents;
}
void Course::setVariables(char *name, int hours, int students) // setting variables of course
{
    char *newName = new char[strlen(name)];
    strcpy(newName, name);
    this->name = newName;
    weeklyHours = hours;
    numberOfStudents = students;
}

