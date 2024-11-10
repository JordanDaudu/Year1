//
// Created by Jordan Daudu on 21/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT4_2_PERSON_H
#define S_2_PROJECTASSIGNMENT4_2_PERSON_H
#include <iostream>
using namespace std;

class Person
        {
        private:
            char *name;
            long id;
        public:
            Person();
            Person(char *n, long id);
            Person(const Person &p);
            ~Person();
            void setParameters(char *n, long id);
            Person &operator=(const Person &p);
            bool operator==(const Person &p) const;
            friend ostream &operator<<(ostream &os, const Person &p);
        };



#endif //S_2_PROJECTASSIGNMENT4_2_PERSON_H
