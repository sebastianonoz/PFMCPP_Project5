#include <iostream>
#include "CoreOfPlane.h"

CoreOfPlane::CoreOfPlane()
{
    std::cout << "CoreOfPlane being constructed" << std::endl;
}

CoreOfPlane::~CoreOfPlane()
{
    std::cout << "CoreOfPlane being deconstructed" << std::endl;
}

void CoreOfPlane::adjustPressures()
{
    tb.increasePressure(50);
    fs.maintainInternalPressure();
}

void CoreOfPlane::startUp()
{
    eg.engageThrust(tb, true);
    fs.encloseCabin();
    fs.supportWingsAndTail();
}
