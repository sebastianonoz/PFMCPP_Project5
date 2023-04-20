#include <iostream>
#include "GuitarCollector.h"

GuitarCollector::GuitarCollector()
{
    std::cout << "GuitarCollector being constructed" << std::endl;
}

GuitarCollector::~GuitarCollector()
{
    std::cout << "GuitarCollector being deconstructed" << std::endl;
}

void GuitarCollector::raiseMultipleVolumes()
{
    gib.increaseVolume(70);
    lp.increaseVolume(50);
}

void GuitarCollector::tuneAll()
{
    gib.tune(.03f);
    lp.tune(.04f);
}
