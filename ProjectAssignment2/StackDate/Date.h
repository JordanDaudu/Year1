//
// Created by Jordan Daudu on 11/07/2024.
//

#ifndef S_2_PROJECTASSIGNMENT2_1_DATE_H
#define S_2_PROJECTASSIGNMENT2_1_DATE_H
#include <iostream>
using namespace std;

class Date
        {
        private:
            int day;
            int month;
            int year;
        public:
            Date();
            Date(int d, int m, int y);
            Date(const Date &p);
            Date& operator=(const Date &p);
            bool operator<(const Date &p) const;
            friend ostream& operator<<(ostream &os, const Date &p);
};


#endif //S_2_PROJECTASSIGNMENT2_1_DATE_H
