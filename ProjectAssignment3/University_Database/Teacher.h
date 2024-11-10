//
// Created by Jordan Daudu on 05/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_2_TEACHER_H
#define S_2_PROJECTASSIGNMENT3_2_TEACHER_H
#include "Course.h"
#include "Worker.h"

class Teacher : virtual public Worker
        {
        protected:
            int sizeCourses;
            Course *arrCourse;
        public:
            Teacher();
            Teacher(char *name, int seniority, int size, Course *arr);
            virtual ~Teacher();
            virtual long salary() const;
            virtual void printOver100Students() const;
            virtual char *getType() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_2_TEACHER_H
