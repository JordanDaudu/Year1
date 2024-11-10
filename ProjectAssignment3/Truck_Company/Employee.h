//
// Created by Jordan Daudu on 04/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_1_EMPLOYEE_H
#define S_2_PROJECTASSIGNMENT3_1_EMPLOYEE_H
#include "Delivery.h"

class Employee
        {
        protected:
            char *name;
            long id;
            int seniority;
        public:
            Employee();
            Employee(char *name, long id, int seniority);
            virtual ~Employee();
            virtual char *getType() const = 0;
            char* getName() const;
            long getId() const;
            int getSeniority() const;
            virtual void print() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_1_EMPLOYEE_H
