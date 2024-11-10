#include <iostream>
#include <cstring>
#include "MyString.h"
#define MAX 30
using namespace std;
unsigned long MyString::total_Length = 0, MyString::total_Digits = 0;
ostream &operator<<(ostream &os, const MyString &d) // cout operator for MyString object
{
    os << d.str;
    return os;
}
istream &operator>>(istream &is, MyString &d) // cin operator for MyString object
{
    char tmp[MAX];
    is >> tmp;
    d = tmp;
    return is;
}
int maxLength(int p1, int p2, int p3) // finding maxlength
{
    if(p1 >= p2 && p1 >= p3)
        return p1;
    if(p2 >= p1 && p2 >= p3)
        return p2;
    else
        return p3;
}

int main()
{
    char tmp[MAX], c;
    int multiplier;
    cout << "Type first string for A: ";
    cin >> tmp;
    MyString A(tmp);
    cout << "Type second string for B: ";
    cin >> tmp;
    MyString B(tmp);
    MyString C=A;
    C+=B;
    cout << "A = " << A << "\n" << "B = " << B << "\n" << "C = " << C << endl;
    MyString::print();
    cout << "Type a new string for C: ";
    cin >> C;
    cout << "A = " << A << "\n" << "B = " << B << "\n" << "C = " << C << endl;
    MyString::print();
    cout << "Type a single char to delete from every string: ";
    cin >> c;
    A-=c;
    B-=c;
    C-=c;
    cout << "A = " << A << "\n" << "B = " << B << "\n" << "C = " << C << endl;
    MyString::print();
    cout << "Type how many times to multiply the string of A (digit): ";
    do
    {
        cin >> multiplier;
        if(multiplier <= 0)
            cout << "Negative and zero is not supported, please input again: ";
    }
    while(multiplier <= 0);
    A*=multiplier;
    cout << "A = " << A << "\n" << "B = " << B << "\n" << "C = " << C << endl;
    MyString::print();
    cout << "Max length = " << maxLength(A,B,C);
    return 0;
}
