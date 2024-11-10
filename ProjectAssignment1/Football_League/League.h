//
// Created by Jordan Daudu on 27/06/2024.
//

#ifndef S_2_PROJECTASSIGNMENT1_1_LEAGUE_H
#define S_2_PROJECTASSIGNMENT1_1_LEAGUE_H

#include "Team.h"
class League
        {
        private:
            int size;
            Team *arr;
        public:
            League(int size, char **names);
            ~League();
            bool game(int points1, char* group1, int points2, char* group2);
            void print() const;
        };


#endif //S_2_PROJECTASSIGNMENT1_1_LEAGUE_H
