//
// Created by Jordan Daudu on 04/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_1_MECHANIC_H
#define S_2_PROJECTASSIGNMENT3_1_MECHANIC_H
#include "Employee.h"

class Mechanic : public Employee
        {
        private:
            int overtimeHours;
        public:
            Mechanic();
            Mechanic(char *name, long id, int seniority, int overtimeHours);
            virtual ~Mechanic();
            int getOvertimeHours() const;
            virtual char *getType() const;
            virtual void print() const;
            virtual int salary() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_1_MECHANIC_H
