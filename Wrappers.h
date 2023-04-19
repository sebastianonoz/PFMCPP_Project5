#pragma once

struct Guitar;
struct Engines;
struct Fuselage;
struct GuitarCollector;
struct CoreOfPlane;

struct GuitarWrapper
{
    Guitar* gtrPtr = nullptr;
    GuitarWrapper( Guitar* ptrToGuitar );
    ~GuitarWrapper();
};


struct EnginesWrapper
{
    Engines* egPtr = nullptr;
    EnginesWrapper( Engines* ptrToEngines );
    ~EnginesWrapper();
};


struct FuselageWrapper
{
    Fuselage* fusPtr = nullptr;
    FuselageWrapper( Fuselage* ptrToFuselage );
    ~FuselageWrapper();
};


struct GcWrapper
{
    GuitarCollector* gcPtr = nullptr;
    GcWrapper( GuitarCollector* ptrToGuitarCollector );
    ~GcWrapper();
};

struct CopWrapper
{
    CoreOfPlane* copPtr = nullptr;
    CopWrapper( CoreOfPlane* ptrToCop );
    ~CopWrapper();
};
