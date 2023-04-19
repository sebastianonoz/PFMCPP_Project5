#pragma once
#include "LeakedObjectDetector.h"

struct Fuselage
{
    int length; int width; int capacity;
    float height; float drag;

    Fuselage();
    ~Fuselage();

    void encloseCabin();
    void supportWingsAndTail();
    void maintainInternalPressure();
    void receivePassengers(int passengerCount);
    void displayCapacity();

    JUCE_LEAK_DETECTOR(Fuselage)
};
