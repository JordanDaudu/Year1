//
// Created by Jordan Daudu on 12/07/2024.
//

#include "MyString.h"
#include <cstring>

MyString::MyString() // constructor
{
    str = nullptr;
}
MyString::MyString(char *word) // constructor with string
{
    str = new char[strlen(word) + 1];
    strcpy(str, word);
    total_Length += strlen(str);
    for(int i = 0; i < strlen(str); i++)
        if(str[i] >= '0' && str[i] <= '9')
            total_Digits++;
}
MyString::MyString(const MyString &word) // constructor with another object
{
    if(this != &word)
    {
        str = new char[strlen(word.str) + 1];
        strcpy(str, word.str);
        total_Length += strlen(str);
        for(int i = 0; i < strlen(str); i++)
            if(str[i] >= '0' && str[i] <= '9')
                total_Digits++;
    }
}
MyString::~MyString() // destructor
{
    total_Length -= strlen(str);
    for(int i = 0; i < strlen(str); i++)
        if(str[i] >= '0' && str[i] <= '9')
            total_Digits--;
    delete[] str;
}

MyString &MyString::operator=(const MyString &word) // operator =
{
    if(this != &word)
    {
        if(this->str)
        {
            total_Length -= strlen(str);
            for(int i = 0; i < strlen(str); i++)
                if(str[i] >= '0' && str[i] <= '9')
                    total_Digits--;
            delete[] str;
        }
        str = new char[strlen(word.str) + 1];
        strcpy(str, word.str);
        total_Length += strlen(str);
        for(int i = 0; i < strlen(str); i++)
            if(str[i] >= '0' && str[i] <= '9')
                total_Digits++;
    }
    return *this;
}
void MyString::operator+=(const MyString &word) // operator +=
{
    char* tmp = new char[(strlen(this->str)) + strlen(word.str) + 1];
    strcpy(tmp, this->str);
    strcat(tmp, word.str);
    delete[] this->str;
    this->str = tmp;
    total_Length += strlen(word.str);
    for(int i = 0; i < strlen(word.str); i++)
        if(word.str[i] >= '0' && word.str[i] <= '9')
            total_Digits++;
}
void MyString::operator-=(const char c) // operator -=
{
    int counter = 0, i, p = 0;
    for(i = 0; i < strlen(this->str); i++)
        if(this->str[i] != c)
            counter++;

    total_Length -= (strlen(str) - counter);
    if(c >= '0' && c <= '9')
        for(i = 0; i < (strlen(str) - counter); i++)
            total_Digits--;

    char* tmp = new char[counter + 1];
    for(i = 0; i < strlen(this->str); i++)
        if(this->str[i] != c)
            tmp[p++] = str[i];
    tmp[p] = '\0';
    delete[] this->str;
    this->str = tmp;
}
void MyString::operator*=(const int c) // operator *=
{
    total_Length -= strlen(str);
    for(int i = 0; i < strlen(str); i++)
        if(str[i] >= '0' && str[i] <= '9')
            total_Digits--;
    char* tmp = new char[strlen(this->str) * c + 1];
    strcpy(tmp, this->str);
    for(int i = 0; i < c-1; i++)
        strcat(tmp, this->str);
    delete[] this->str;
    this->str = tmp;
    total_Length += strlen(str);
    for(int i = 0; i < strlen(str); i++)
        if(str[i] >= '0' && str[i] <= '9')
            total_Digits++;
}
void MyString::print() // printing statics
{
    cout << "Total length = " << total_Length << endl;
    cout << "Total digits = " << total_Digits << endl;
}

MyString::operator int() const // converting from MyString object to int
{
    return int(strlen(this->str));
}
