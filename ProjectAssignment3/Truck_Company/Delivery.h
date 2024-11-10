//
// Created by Jordan Daudu on 04/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT3_1_DELIVERY_H
#define S_2_PROJECTASSIGNMENT3_1_DELIVERY_H


class Delivery
        {
        private:
            int distance;
            int weight;
        public:
            Delivery();
            Delivery(int distance, int weight);
            ~Delivery();
            Delivery& operator=(const Delivery &other);
            int getDistance() const;
            int getWeight() const;
            void setDistance(int d);
            void setWeight(int w);
        };


#endif //S_2_PROJECTASSIGNMENT3_1_DELIVERY_H
