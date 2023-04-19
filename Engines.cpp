#include <iostream>
#include "Engines.h"

Engines::Engines() :
numEngines(2),
powerOutput(.30f),
fuelEfficiency(10.f),
emissions(20.f),
size(20),
engineSpeed(0)
{
    std::cout << "Engines being constructed!" << std::endl;
}

Engines::~Engines()
{
    std::cout << "Engines being deconstructed" << std::endl;
}

Engines::Turbines::Turbines() :
lowPressureLength(84),
highPressureWidth(93),
fuelReleased(0),
brand("GE"),
model("CF3942"),
material("Titanium"),
currentSpeed(0),
thrustLevel(0),
currentPressure(.00f)
{
    std::cout << "Turbines being constructed!" << std::endl;
}

Engines::Turbines::~Turbines()
{
    std::cout << "Turbines being deconstructed" << std::endl;
}

void Engines::Turbines::increaseThrustLevel(int targetLevel)
{
    if(targetLevel == 20)
    {
        thrustLevel += 20;
        std::cout << "Thrust level increased to " << thrustLevel << std::endl;
    }
}
void Engines::Turbines::increaseSpeed(int targetSpeed)
{
    if(targetSpeed == 20)
    {
        currentSpeed += 20;
        std::cout << "Speed increased to " << currentSpeed << std::endl;
    }
}
void Engines::Turbines::increasePressure(int targetPressure)
{
    if(targetPressure == 40)
    {
        currentPressure += 40;
        std::cout << "Pressure increased to " << currentPressure << std::endl;
    }
}

void Engines::Turbines::displayMaterial() const
{
    std::cout << "The material of the turbines is: " << this->material << std::endl;
}

void Engines::Turbines::releaseFuel(int amount)
{
    while (fuelReleased < amount)
    {
        fuelReleased += 2;
        std::cout << "Releasing fuel... " << fuelReleased << " liters released so far." << std::endl;
    }
}

bool Engines::engageThrust(Turbines& thrust, bool turbinesEngaged)
{
    if(turbinesEngaged == true)
    {
        int targetLevel = 20;
        thrust.increaseThrustLevel(targetLevel);
        return true;
    }
    
    return false;
}
void Engines::increasePower(int amountOfIncrease)
{
    if(amountOfIncrease == 40)
    {
        powerOutput += 40;
        std::cout << "Power output increased to " << powerOutput << std::endl;
    }
}
void Engines::controlSpeed()
{
    if(engineSpeed == 0)
    {
        engineSpeed += 10;
        std::cout << "Speed controlled to " << engineSpeed << std::endl;
    }
}

void Engines::displaySize() const
{
    std::cout << "Size of engines: " << this->size << std::endl;
}
