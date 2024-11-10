//
// Created by Jordan Daudu on 05/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_2_WORKER_H
#define S_2_PROJECTASSIGNMENT3_2_WORKER_H


class Worker
        {
        protected:
            char *name;
            int seniority;
        public:
            Worker();
            Worker(char *name, int seniority);
            virtual ~Worker();
            virtual char *getName() const;
            virtual long salary() const;
            virtual char *getType() const;
        };


#endif //S_2_PROJECTASSIGNMENT3_2_WORKER_H
