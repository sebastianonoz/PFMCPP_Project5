#include <iostream>
#include "Fuselage.h"

Fuselage::Fuselage() :
length(40),
width(60),
capacity(10),
height(19.f),
drag(32.2f)
{
    std::cout << "Fuselage being constructed!" << std::endl;
}

Fuselage::~Fuselage()
{
    std::cout << "Fuselage being deconstructed" << std::endl;
}

void Fuselage::encloseCabin()
{
    std::cout << "Cabin enclosed." << std::endl;
}
void Fuselage::supportWingsAndTail()
{
    std::cout << "Supporting wings and tail." << std::endl;
}
void Fuselage::maintainInternalPressure() const
{
    if(capacity >= 50)
    {
        std::cout << "Maintaining internal pressure at a capacity of: "<< capacity << std::endl;
    }
    else
    {
        std::cout << "Cannot maintain internal pressure. Increase capacity." << std::endl;
    }
}

void Fuselage::receivePassengers(int passengerCount)
{
    int availableCap = capacity;
    for (int i = 0; i < passengerCount; ++i)
    {
        if (availableCap > 0)
        {
            --availableCap;
            std::cout << "Passenger " << i + 1 << " has boarded. " << availableCap <<" more passengers can fit." << std::endl;
        }
        else
        {
            std::cout << "Fuselage is at full capacity. Cannot board any more passengers." << std::endl;
        }
    }
}

void Fuselage::displayCapacity() const
{
    std::cout << "The fuselage can hold up to " << this->capacity << " passengers" << std::endl;
}
