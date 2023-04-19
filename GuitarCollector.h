#pragma once
#include "LeakedObjectDetector.h"
#include "Guitar.h"

struct GuitarCollector
{
    Guitar gib;
    Guitar lp;
    
    void raiseMultipleVolumes();
    void tuneAll();
    GuitarCollector();
    ~GuitarCollector();

    JUCE_LEAK_DETECTOR(GuitarCollector)
};
