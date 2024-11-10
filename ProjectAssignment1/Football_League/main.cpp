#include <iostream>
#include <cstring>
#include "League.h"
#define MAX 20
using namespace std;
int main()
{
    int size, points1, points2; // initializing variables
    char **names = nullptr;
    char name1[MAX], name2[MAX];
    bool game = true;
    cout << "~~~~~WELCOME~~~~~" << endl;
    do // checking there is at least 2 teams chosen in a league
    {
        cout << "How many teams there is in the league? ";
        cin >> size;
        cin.ignore();
        if(size <= 1)
            cout << "Input error, please type in a positive number and at least have 2 teams." << endl;
    }
    while(size <= 1);
    names = new char*[size]; // allocating dynamic memory necessary
    for(int i = 0; i < size; i++) // getting all teams names and setting them in dynamic char
    {
        cout << "Team name " << i+1 << ": ";
        cin.getline(name1,MAX);
        names[i] = new char[strlen(name1) + 1];
        strcpy(names[i], name1);
    }
    League league(size, names); // initializing league
    while(game) // game loop
    {
        cout << "\n~~~Game Start~~~" << endl;
        cout << "Type First team name: ";
        cin.getline(name1,MAX);
        cout << "Type second team name: ";
        cin.getline(name2,MAX);
        cout << "How many goals " << name1 << " has scored? ";
        do // checking that scores for first team are not negative
        {
            cin >> points1;
            if(points1 < 0)
                cout << "Can't score a negative number of goals, input again: ";
        }
        while(points1 < 0);
        cout << "How many goals " << name2 << " has scored? ";
        do // checking that scores for second team are not negative
        {
            cin >> points2;
            if(points2 < 0)
                cout << "Can't score a negative number of goals, input again: ";
        }
        while(points2 < 0);
        cout << endl;
        league.game(points1,name1,points2,name2); // updating parameters of each team
        league.print(); // printing all teams parameters
        cout << "\nWould you like to play another game?" << endl; // checking if user would like to play another game
        cout << "Press 1 to continue  ||  Press 0 to stop" << endl;
        cin >> game;
        if(game)
            cin.ignore();
    }
    for(int i = 0; i < size; i++) // deleting dynamic memory correctly
        delete[] names[i];
    delete[] names;
    return 0;
}
