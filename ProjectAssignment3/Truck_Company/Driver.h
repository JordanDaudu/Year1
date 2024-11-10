//
// Created by Jordan Daudu on 04/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_1_DRIVER_H
#define S_2_PROJECTASSIGNMENT3_1_DRIVER_H
#include "Employee.h"
#include "Delivery.h"

class Driver : public Employee
        {
        private:
            Delivery *packages;
            int numberOfDeliveries;
            static int over8000KgDeliveries;
        public:
            Driver();
            Driver(char *name, long id, int seniority, Delivery *arr, int size);
            virtual ~Driver();
            virtual void addPackage(const Delivery arr);
            virtual char *getType() const;
            virtual void print() const;
            static void printStatic();
            virtual int salary() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_1_DRIVER_H
