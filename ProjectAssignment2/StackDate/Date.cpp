//
// Created by Jordan Daudu on 11/07/2024.
//
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date() // constructor
{
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y) // constructor with parameters
{
    day = d;
    month = m;
    year = y;
}

Date::Date(const Date &p) // constructor with another object
{
    day = p.day;
    month = p.month;
    year = p.year;
}

Date& Date::operator=(const Date &p) // operator =
{
    this->day = p.day;
    this->month = p.month;
    this->year = p.year;
    return *this;
}

bool Date::operator<(const Date &d) const // operator <
{
    if(year < d.year)
        return true;
    if(year == d.year && month < d.month)
        return true;
    return(year == d.year && month == d.month && day < d.day);
}

ostream &operator<<(ostream &os, const Date &p) // cin operator
{
    os << p.day << "/" << p.month << "/" << p.year;
    return os;
}