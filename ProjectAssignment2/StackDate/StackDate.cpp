//
// Created by Jordan Daudu on 11/07/2024.
//

#include "StackDate.h"

StackDate::StackDate() // constructor
{
    p = nullptr;
    size = 0;
}
StackDate::StackDate(const StackDate &d) // constructor
{
    if(d.size != 0)
    {
        this->size = d.size;
        this->p = new Date[d.size];
        for(int i = 0; i < d.size; i++)
            this->p[i] = d.p[i];
    }
    else
    {
        this->p = nullptr;
        this->size = 0;
    }
}
StackDate::~StackDate() // destructor
{
    delete[] p;
}

StackDate &StackDate::operator=(const StackDate &d) // operator =
{
    if(this != &d)
    {
        delete[] this->p;
        this->size = d.size;
        this->p = new Date[d.size];
        for(int i = 0; i < d.size; i++)
            this->p[i] = d.p[i];
    }
    return *this;
}

StackDate StackDate::operator+=(const Date &d) // operator +=
{
    Date *newP = new Date[this->size+1];
    for(int i = 0; i < this->size; i++)
        newP[i] = this->p[i];
    newP[size] = d;
    this->size++;
    delete[] this->p;
    this->p = newP;
    return *this;
}

StackDate StackDate::operator--(int) // operator --
{
    if(size > 0)
    {
        Date *newP = new Date[this->size-1];
        for(int i = 0; i < this->size-1; i++)
            newP[i] = this->p[i];
        delete[] this->p;
        this->size--;
        this->p = newP;
        return *this;
    }
    return *this;
}
int StackDate::getSize() const // getting size
{
    return size;
}
Date StackDate::getTop() const // getting size
{
    if(size <= 0)
    {
        Date tmp;
        return tmp;
    }
    else
        return this->p[size-1];
}

Date StackDate::min() const // getting min date
{
    Date pointer;
    if(p == nullptr || size <= 0)
        return pointer;
    pointer = p[0];
    for(int i = 1; i < size; i++)
    {
        if(this->p[i] < pointer)
            pointer = p[i];
    }
    return pointer;
}
Date StackDate::max() const // getting max date
{
    Date pointer;
    if(p == nullptr || size <= 0)
        return pointer;
    pointer = p[0];
    for(int i = 1; i < size; i++)
    {
        if(pointer < this->p[i])
            pointer = p[i];
    }
    return pointer;
}