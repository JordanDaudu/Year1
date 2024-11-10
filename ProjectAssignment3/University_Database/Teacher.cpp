//
// Created by Jordan Daudu on 05/08/2024.
//

#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher() : Worker() // constructor
{
    sizeCourses = 0;
    arrCourse = nullptr;
}
Teacher::Teacher(char *name, int seniority, int size, Course *arr) : Worker(name, seniority) // constructor with parameters
{
    sizeCourses = size;
    arrCourse = arr;
}
Teacher::~Teacher() // destructor
{
    delete[] arrCourse;
}

long Teacher::salary() const // getting salary of teacher
{
    long salary = 400 * seniority;
    for(int i = 0; i < sizeCourses; i++)
    {
        salary += (800 * arrCourse[i].getWeeklyHours());
        if(arrCourse[i].getNumberOfStudents() >= 100)
            salary += 300;
    }
    return salary;
}

void Teacher::printOver100Students() const // printing courses of teacher with over 100 students
{
    for(int i = 0; i < sizeCourses; i++)
        if(arrCourse[i].getNumberOfStudents() >= 100)
            cout << arrCourse[i].getName() << endl;
}

char *Teacher::getType() const // getting class name
{
    return "Teacher";
}
