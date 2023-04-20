#include <iostream>
#include "Wrappers.h"
#include "Guitar.h"
#include "Engines.h"
#include "Fuselage.h"
#include "GuitarCollector.h"
#include "CoreOfPlane.h"

GuitarWrapper::GuitarWrapper( Guitar* ptrToGuitar ) : gtrPtr(ptrToGuitar)
{
    std::cout << "GuitarWrapper being constructed" << std::endl;
}

GuitarWrapper::~GuitarWrapper()
{
    delete gtrPtr;
    std::cout << "GuitarWrapper being deconstructed (deleted gtrPtr)" << std::endl;
}

EnginesWrapper::EnginesWrapper( Engines* ptrToEngines ) : egPtr(ptrToEngines)
{
    std::cout << "EnginesWrapper being constructed" << std::endl;
}

EnginesWrapper::~EnginesWrapper()
{
    delete egPtr;
    std::cout << "EnginesWrapper being deconstructed (deleted egPtr)" << std::endl;
}

FuselageWrapper::FuselageWrapper( Fuselage* ptrToFuselage ) : fusPtr(ptrToFuselage)
{
    std::cout << "FuselageWrapper being constructed" << std::endl;
}

FuselageWrapper::~FuselageWrapper()
{
    delete fusPtr;
    std::cout << "FuselageWrapper being deconstructed (deleted fusPtr)" << std::endl;
}

GcWrapper::GcWrapper( GuitarCollector* ptrToGuitarCollector ) : gcPtr(ptrToGuitarCollector)
{
    std::cout <<  "GcWrapper being constructed" << std::endl;
}

GcWrapper::~GcWrapper()
{
    delete gcPtr;
    std::cout << "GcWrapper being deconstructed (deleted gcPtr)" << std::endl;
}

CopWrapper::CopWrapper( CoreOfPlane* ptrToCop ) : copPtr(ptrToCop)
{
   std::cout << "CopWrapper being constructed" << std::endl; 
}

CopWrapper::~CopWrapper()
{
    delete copPtr;
    std::cout << "CopWrapper being deconstructed (deleted copPtr)" << std::endl;  
}
