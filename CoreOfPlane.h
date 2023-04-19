#pragma once
#include "LeakedObjectDetector.h"
#include "Engines.h"
#include "Fuselage.h"

struct CoreOfPlane
{
    Engines eg;
    Engines::Turbines tb;
    Fuselage fs;

    void adjustPressures();
    void startUp();
    CoreOfPlane();
    ~CoreOfPlane();

    JUCE_LEAK_DETECTOR(CoreOfPlane)

};
