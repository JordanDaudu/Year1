//
// Created by Jordan Daudu on 05/08/2024.
//

#include "Researcher.h"
#include <iostream>
using namespace std;

Researcher::Researcher() : Worker() // constructor
{
    sizeArticles = 0;
    arrArticle = nullptr;
}
Researcher::Researcher(char *name, int seniority, int size, Article *arr) : Worker(name, seniority) // constructor with parameters
{
    sizeArticles = size;
    arrArticle = arr;
}
Researcher::~Researcher() // destructor
{
    delete[] arrArticle;
}

long Researcher::salary() const // getting salary of researcher
{
    return (5000 + (3000 * sizeArticles) + (1000 * seniority));
}

void Researcher::printArticles() const // printing all articles of researcher
{
    for(int i = 0; i < sizeArticles; i++)
        cout << arrArticle[i].getName() << endl;
}

void Researcher::addArticle(char *article) // adding an article to researcher
{
    Article *newArr = new Article[sizeArticles+1];
    for(int i = 0; i < sizeArticles; i++)
        newArr[i] = arrArticle[i];
    delete[] arrArticle;
    newArr[sizeArticles].setName(article);
    arrArticle = newArr;
    sizeArticles++;
}

char *Researcher::getType() const // getting class name
{
    return "Researcher";
}