//
// Created by Jordan Daudu on 27/06/2024.
//

#ifndef S_2_PROJECTASSIGNMENT1_1_TEAM_H
#define S_2_PROJECTASSIGNMENT1_1_TEAM_H


class Team
        {
        private:
            char *name;
            int goodPoints;
            int badPoints;
            int win;
            int draw;
            int loose;
        public:
            Team();
            ~Team();
            void setName(char *str);
            char* getName() const;
            void game(int good, int bad);
            int points() const;
            void print() const;
        };


#endif //S_2_PROJECTASSIGNMENT1_1_TEAM_H
