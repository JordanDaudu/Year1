//
// Created by Jordan Daudu on 11/07/2024.
//

#ifndef S_2_PROJECTASSIGNMENT2_1_STACKDATE_H
#define S_2_PROJECTASSIGNMENT2_1_STACKDATE_H
#include "Date.h"
#include <iostream>
using namespace std;

class StackDate
        {
        private:
            Date *p;
            int size;
        public:
            StackDate();
            StackDate(const StackDate &p);
            ~StackDate();
            StackDate& operator=(const StackDate &d);
            friend ostream& operator<<(ostream &os, const StackDate &p);
            StackDate operator+=(const Date &d);
            StackDate operator--(int);
            int getSize() const;
            Date getTop() const;
            Date min() const;
            Date max() const;
        };


#endif //S_2_PROJECTASSIGNMENT2_1_STACKDATE_H
