#pragma once
#include "LeakedObjectDetector.h"

struct Engines 
{
    int numEngines;
    float powerOutput;
    float fuelEfficiency;
    float emissions;
    int size;
    int engineSpeed;

    struct Turbines
    {
        int lowPressureLength; 
        int highPressureWidth;
        int fuelReleased;
        std::string brand;
        std::string model;
        std::string material;
        int currentSpeed;
        int thrustLevel;
        float currentPressure;

        Turbines();
        ~Turbines();

        void increaseThrustLevel(int targetLevel);
        void increaseSpeed(int targetSpeed);
        void increasePressure(int targetPressure);
        void releaseFuel(int amount);
        void displayMaterial() const;
    };

    Engines();
    ~Engines();


    bool engageThrust(Turbines& thrust,bool turbinesEngaged);
    void increasePower(int amountOfIncrease);
    void controlSpeed();
    void displaySize() const;

    JUCE_LEAK_DETECTOR(Engines)

};
