//
// Created by Jordan Daudu on 05/08/2024.
//

#include "Lecturer.h"
#include <iostream>
using namespace std;

Lecturer::Lecturer() : Teacher(), Researcher(), Worker()  // constructor
{}
Lecturer::Lecturer(char *name, int seniority, Course *courseArr, int coursesSize, Article *articleArr, int articlesSize) : Teacher(name, seniority, coursesSize, courseArr),
                                                                                                                           Researcher(name, seniority, articlesSize, articleArr),
                                                                                                                           Worker(name, seniority) // constructor with parameters
{}
Lecturer::~Lecturer() // destructor
{}

long Lecturer::salary() const
{
    long salary = (2000 * sizeArticles) + (700 * seniority);
    for(int i = 0; i < sizeCourses; i++)
        salary += (1000 * arrCourse[i].getWeeklyHours());
    return salary;
}

void Lecturer::printOver100Students() const // printing all courses of lecturer with over 100 students
{
    Teacher::printOver100Students();
}

void Lecturer::printArticles() const // printing all articles of lecturer
{
    Researcher::printArticles();
}

void Lecturer::addArticle(char *article) // adding an article to lecturer
{
    Researcher::addArticle(article);
}

char *Lecturer::getType() const // getting class name
{
    return "Lecturer";
}