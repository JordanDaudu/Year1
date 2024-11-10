//
// Created by Jordan Daudu on 05/08/2024.
//

#include "Article.h"
#include <cstring>

Article::Article() // constructor
{
    name = nullptr;
}
Article::Article(char *name) // constructor with parameters
{
    char *newName = new char[strlen(name)];
    strcpy(newName, name);
    this->name = newName;
}
Article::~Article() // destructor
{
    delete[] name;
}

void Article::setName(char *name) // setting name of article
{
    if(this->name != nullptr)
        delete[] this->name;
    char *newName = new char[strlen(name)];
    strcpy(newName, name);
    this->name = newName;
}

char *Article::getName() const // getting name of article
{
    return name;
}

Article &Article::operator=(const Article &other) // = operator
{
    if(this != &other)
    {
        if(name != nullptr)
            delete[] name;
        char *newName = new char[strlen(other.name)];
        strcpy(newName, other.name);
        name = newName;
    }
    return *this;
}
