//
// Created by Jordan Daudu on 05/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_2_COURSE_H
#define S_2_PROJECTASSIGNMENT3_2_COURSE_H


class Course
        {
        private:
            char *name;
            int weeklyHours;
            int numberOfStudents;
        public:
            Course();
            Course(char *name, int weeklyHours, int numberOfStudents);
            ~Course();
            char *getName() const;
            int getWeeklyHours() const;
            int getNumberOfStudents() const;
            void setVariables(char *name, int hours, int students);
        };


#endif //S_2_PROJECTASSIGNMENT3_2_COURSE_H
