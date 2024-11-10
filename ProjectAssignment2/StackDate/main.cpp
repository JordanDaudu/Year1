#include <iostream>
#include "StackDate.h"
using namespace std;

ostream &operator<<(ostream &os, const StackDate &d)
{
    for(int i = 0; i < d.size; i++)
        os << d.p[i] << endl;
    return os;
}

int main() {
    StackDate s1;
    int choice, day, month, year;
    do // do loop at least once, if choice = 8 leave loop else re-do loop
    {
        cout << "\n~~~~~Stack Menu~~~~~" << endl;
        cout << "1.Add date to stack\n2.delete top date from stack\n3.Print date stack\n4.Print top of date stack\n5.Stack size\n6.Max date in stack\n7.Min date in stack\n8.Exit" << endl; // printing menu
        cin >> choice; // receives input from user for choice
        switch (choice) // choosing a case depending on choice
        {
            case 1: // add date to stack
            {
                cout << "Input date to add to stack in DD MM YYYY format: ";
                cin >> day >> month >> year;
                Date tmp(day, month, year);
                s1 += tmp;
                break;
            }
            case 2: // delete top date from stack
                cout << "Deleting top date from stack..." << endl;
                if(s1.getSize() > 0)
                    cout << "Deleted successfully!" << endl;
                else
                    cout << "Stack is empty!" << endl;
                s1--;
                break;
            case 3: // print date stack
                cout << "Printing entire stack..." << endl;
                if(s1.getSize() == 0)
                    cout << "Stack is empty!" << endl;
                cout << s1;
                break;
            case 4: // print top of date stack
                cout << "Printing top of stack..." << endl;
                cout << s1.getTop();
                break;
            case 5: // stack size
                cout << "The size of the stack is " << s1.getSize() << endl;
                break;
            case 6: // max date in stack
                cout << "Max date in stack is: " << s1.max() << endl;
                break;
            case 7: // min date in stack
                cout << "Min date in stack is: " << s1.min() << endl;
                break;
            case 8: // exit
                cout << "Goodbye" << endl;
                break;
            default: // default if choice wasn't any of the others
                cout << "Input not supported! please type in a supported choice" << endl;
                break;
        }
    }
    while(choice != 8);
    return 0;
}