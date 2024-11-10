//
// Created by Jordan Daudu on 05/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_2_ARTICLE_H
#define S_2_PROJECTASSIGNMENT3_2_ARTICLE_H


class Article
        {
        private:
            char *name;
        public:
            Article();
            Article(char *name);
            ~Article();
            void setName(char *name);
            char *getName() const;
            Article& operator=(const Article &other);
        };


#endif //S_2_PROJECTASSIGNMENT3_2_ARTICLE_H
