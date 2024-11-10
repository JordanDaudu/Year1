//
// Created by Jordan Daudu on 05/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_2_RESEARCHER_H
#define S_2_PROJECTASSIGNMENT3_2_RESEARCHER_H
#include "Article.h"
#include "Worker.h"

class Researcher : virtual public Worker
        {
        protected:
            int sizeArticles;
            Article *arrArticle;
        public:
            Researcher();
            Researcher(char *name, int seniority, int size, Article *arr);
            virtual ~Researcher();
            virtual long salary() const;
            virtual void printArticles() const;
            virtual void addArticle(char *article);
            virtual char *getType() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_2_RESEARCHER_H
