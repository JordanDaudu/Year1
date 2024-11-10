//
// Created by Jordan Daudu on 12/07/2024.
//

#ifndef S_2_PROJECTASSIGNMENT2_2_MYSTRING_H
#define S_2_PROJECTASSIGNMENT2_2_MYSTRING_H
#include <iostream>
using namespace std;

class MyString
    {
    private:
        char* str;
        static unsigned long total_Length;
        static unsigned long total_Digits;
    public:
        MyString();
        MyString(char* word);
        MyString(const MyString &word);
        ~MyString();
        MyString& operator=(const MyString &word);
        friend ostream& operator<<(ostream &os, const MyString &p);
        friend istream& operator>>(istream &is, MyString &p);
        void operator+=(const MyString &word);
        void operator-=(const char c);
        void operator*=(const int c);
        static void print();
        operator int() const;
    };

#endif //S_2_PROJECTASSIGNMENT2_2_MYSTRING_H
