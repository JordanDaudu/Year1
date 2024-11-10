//
// Created by Jordan Daudu on 27/06/2024.
//

#include "Team.h"
#include <iostream>
#include <cstring>
using namespace std;

Team::Team() // constructing function
{
    name = nullptr;
    goodPoints = 0;
    badPoints = 0;
    win = 0;
    draw = 0;
    loose = 0;
}
Team::~Team() // destructor function
{
    delete[] name;
}

void Team::setName(char *str) // setting name variable to team with correct allocation of memory
{
    if(name) // fail-safe if there is already a name
        delete[] name;
    name = new char[strlen(str) + 1];
    strcpy(name, str);
}
char* Team::getName() const // getting name of object
{
    return name;
}
void Team::game(int good, int bad) // updating parameters after a game
{
    goodPoints = goodPoints + good;
    badPoints = badPoints + bad;
    if(good == bad)
        draw++;
    else if(good > bad)
        win++;
    else
        loose++;
}
int Team::points() const // calculating team points and returning
{
    return draw + (win*3);
}
void Team::print() const // printing all parameters
{
    cout << "||Name:" << name << " Goals:" << goodPoints << " Goals taken:" << badPoints << " Wins:" << win << " Draws:" << draw << " Looses:" << loose << " Points: " << points() << endl;
}