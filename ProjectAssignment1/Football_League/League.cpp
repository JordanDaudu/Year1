//
// Created by Jordan Daudu on 27/06/2024.
//

#include "League.h"
#include <iostream>
#include <cstring>
using namespace std;

League::League(int size, char **names) // constructing function, setting size of league and names of each team
{
    this -> size = size;
    arr = new Team[size];
    for (int i = 0; i < size; i++)
    {
        arr[i].setName(names[i]);
    }
}
League::~League() // destructor function
{
    delete[] arr;
}
bool League::game(int points1, char *group1, int points2, char *group2) // game loop
{
    bool result;
    int index1, index2, i;
    for(i = 0; i < size; i++) // checking if first team is in the league
    {
        result = false;
        if(strcmp(arr[i].getName(), group1) == 0)
        {
            result = true;
            index1 = i;
            break;
        }
    }
    if (!result) // if first team isn't in the team return 0
    {
        cout << "Team name given isn't in the league! Score wasn't updated!\n" << endl;
        return result;
    }
    for(i = 0; i < size; i++) // checking if second team is in the league
    {
        result = false;
        if(strcmp(arr[i].getName(), group2) == 0)
        {
            result = true;
            index2 = i;
            break;
        }
    }
    if (!result) // if second team isn't in the team return 0
    {
        cout << "Team name given isn't in the league! Score wasn't updated!\n" << endl;
        return result;
    }
    arr[index1].game(points1, points2); // calling game function from team to update score of team 1
    arr[index2].game(points2, points1); // calling game function from team to update score of team 2
    return true; // returning 1
}
void League::print() const // printing all teams parameters
{
    for(int i = 0; i < size; i++)
        arr[i].print();
}