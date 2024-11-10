//
// Created by Jordan Daudu on 04/08/2024.
//

#include "Delivery.h"

Delivery::Delivery() // constructor
{
    distance = 0;
    weight = 0;
}

Delivery::Delivery(int distance, int weight) // constructor with parameters
{
    this->distance = distance;
    this->weight = weight;
}

Delivery::~Delivery() {} // destructor

Delivery &Delivery::operator=(const Delivery &other) // = operator
{
    if(this != &other)
    {
        distance = other.distance;
        weight = other.weight;
    }
    return *this;
}

int Delivery::getDistance() const // getting distance of object
{
    return distance;
}

int Delivery::getWeight() const // getting weight of object
{
    return weight;
}

void Delivery::setDistance(int d) // setting distance of object
{
    distance = d;
}

void Delivery::setWeight(int w) // setting weight of objects
{
    weight = w;
}
