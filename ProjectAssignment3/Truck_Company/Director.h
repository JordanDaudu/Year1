//
// Created by Jordan Daudu on 04/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_1_DIRECTOR_H
#define S_2_PROJECTASSIGNMENT3_1_DIRECTOR_H
#include "Employee.h"

class Director : public Employee
        {
        public:
            Director();
            Director(char *name, long id, int seniority);
            ~Director();
            virtual char *getType() const;
            virtual void print() const;
            virtual int salary() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_1_DIRECTOR_H
