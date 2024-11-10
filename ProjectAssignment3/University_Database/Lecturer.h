//
// Created by Jordan Daudu on 05/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_2_LECTURER_H
#define S_2_PROJECTASSIGNMENT3_2_LECTURER_H
#include "Teacher.h"
#include "Researcher.h"

class Lecturer : public Teacher, public Researcher
        {
        public:
            Lecturer();
            Lecturer(char *name, int seniority, Course *courseArr, int coursesSize, Article *articleArr, int articlesSize);
            virtual ~Lecturer();
            virtual long salary() const;
            virtual void printOver100Students() const;
            virtual void printArticles() const;
            virtual void addArticle(char *article);
            virtual char *getType() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_2_LECTURER_H
