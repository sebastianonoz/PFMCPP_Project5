/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */




/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
#include <iostream>
#include "LeakedObjectDetector.h"
// Copied UDT #1

struct Guitar
{
    int numStrings = 6;
    int numFrets = 22;
    int volumeLevel = 40;
    std::string brand = "Gibson";
    std::string material = "Spruce Wood";
    bool inTune;

    struct Strings
    {
        float lowEStringGauge = .040f; 
        float dStringGauge = .010f;
        std::string brand = "Ernie Ball";
        std::string sku = "2229";
        std::string material ="Nickel";
        int currentPitchST;

        Strings();
        ~Strings();
        
        void bend(std::string whichString, bool bendUp);
        void slide(std::string currentNote, std::string targetNote);
        bool snap();
        void displayCurrentPitchST();
    };

    Guitar();
    ~Guitar();

    bool playNote(std::string whichNote);
    void tune(float CurrentCent);
    bool makePercussiveNoise();
    void increaseVolume(int targetVolume);   
    void displayVolumeLevel();

    JUCE_LEAK_DETECTOR(Guitar)
    
};

Guitar::Guitar() :
inTune(false)
{
    std::cout << "Guitar being constructed!" << std::endl;
}

Guitar::~Guitar()
{
    std::cout << "Guitar being deconstructed" << std::endl;
}

Guitar::Strings::Strings() :
currentPitchST(2)
{
    std::cout << "Strings being constructed!" << std::endl;
}

Guitar::Strings::~Strings()
{
    std::cout << "Strings being deconstructed" << std::endl;
}



void Guitar::Strings::bend(std::string whichString, bool bendUp)
{
    if(whichString == "Low E")
    {
        bendUp = false;
    }
    if(whichString == "A")
    {
        currentPitchST += 2;
        std::cout << "Bending note up to: " << currentPitchST << std::endl;
    }
}
void Guitar::Strings::slide(std::string currentNote, std::string targetNote)
{
    if(targetNote == "A")
    {
        if(currentNote == "G")
        {
            currentPitchST += 2;
            std::cout << "Sliding up to: " << currentPitchST << std::endl;
        }
    }
}
bool Guitar::Strings::snap()
{
    return true;
}

void Guitar::Strings::displayCurrentPitchST()
{
    std::cout << "Current pitch ST: " << this->currentPitchST << std::endl;
}

bool Guitar::playNote(std::string whichNote)
{
    if(whichNote == "F")
    {
        std::cout << "Now playing " << whichNote << " ." << std::endl;
        return true;
    }
    
    return false;
}

void Guitar::tune(float currentCent)
{
    if(currentCent == .00f)
    {
        inTune = true;
    }
    else
    {
        inTune = false;
        currentCent = 0;
        std::cout << "Current tuning is: " << currentCent << std::endl;
    }  
}
bool Guitar::makePercussiveNoise()
{
    std::cout << "tap tap tap" << std::endl;
    return true;
}

void Guitar::increaseVolume(int targetVolume)
{
    while (volumeLevel < targetVolume)
    {
        ++volumeLevel;
        std::cout << "Increasing volume to " << volumeLevel << std::endl; 
        if (volumeLevel == targetVolume)
        {
            std::cout << "At desired volume" << std::endl;
        }    
    }
}

void Guitar::displayVolumeLevel()
{
    std::cout << "Current volume level is: " << this->volumeLevel << std::endl;
}


struct GuitarWrapper
{
    Guitar* gtrPtr = nullptr;
    GuitarWrapper( Guitar* ptrToGuitar ) : gtrPtr(ptrToGuitar)
    {
        std::cout << "GuitarWrapper being constructed" << std::endl;
    }
    ~GuitarWrapper()
    {
        delete gtrPtr;
        std::cout << "GuitarWrapper being deconstructed (deleted gtrPtr)" << std::endl;
    }
};





// Copied UDT 2

struct Engines 
{
    int numEngines = 2;
    float powerOutput;
    float fuelEfficiency = 10.f;
    float emissions = 20.f;
    int size = 20;
    int engineSpeed = 0;

    struct Turbines
    {
        int lowPressureLenth = 84; 
        int highPressureWidth = 93;
        int fuelReleased = 0;
        std::string brand = "GE";
        std::string model = "CF3942";
        std::string material ="Titanium";
        int currentSpeed;
        int thrustLevel;
        float currentPressure;

        Turbines();
        ~Turbines();

        void increaseThrustLevel(int targetLevel);
        void increaseSpeed(int targetSpeed);
        void increasePressure(int targetPressure);
        void releaseFuel(int amount);
        void displayMaterial();
    };

    Engines();
    ~Engines();


    bool engageThrust(Turbines& thrust,bool turbinesEngaged);
    void increasePower(int amountOfIncrease);
    void controlSpeed();
    void displaySize();

    JUCE_LEAK_DETECTOR(Engines)

};

Engines::Engines() :
powerOutput{.30f}
{
    std::cout << "Engines being constructed!" << std::endl;
}

Engines::~Engines()
{
    std::cout << "Engines being deconstructed" << std::endl;
}

Engines::Turbines::Turbines() :
currentSpeed(0),
thrustLevel(0),
currentPressure{.00f}
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

void Engines::Turbines::displayMaterial()
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

void Engines::displaySize()
{
    std::cout << "Size of engines: " << this->size << std::endl;
}


struct EnginesWrapper
{
    Engines* egPtr = nullptr;
    EnginesWrapper( Engines* ptrToEngines ) : egPtr(ptrToEngines)
    {
        std::cout << "EnginesWrapper being constructed" << std::endl;
    }
    ~EnginesWrapper()
    {
        delete egPtr;
        std::cout << "EnginesWrapper being deconstructed (deleted egPtr)" << std::endl;
    }
};



// Copied UDT 3
struct Fuselage
{
    int length; int width; int capacity;
    float height = 19.f;
    float drag = 32.2f;

    Fuselage();
    ~Fuselage();

    void encloseCabin();
    void supportWingsAndTail();
    void maintainInternalPressure();
    void receivePassengers(int passengerCount);
    void displayCapacity();

    JUCE_LEAK_DETECTOR(Fuselage)
};

Fuselage::Fuselage() :
length(40),
width(60),
capacity(10)
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
void Fuselage::maintainInternalPressure()
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

void Fuselage::displayCapacity()
{
    std::cout << "The fuselage can hold up to " << this->capacity << " passengers" << std::endl;
}

struct FuselageWrapper
{
    Fuselage* fusPtr = nullptr;
    FuselageWrapper( Fuselage* ptrToFuselage ) : fusPtr(ptrToFuselage)
    {
        std::cout << "FuselageWrapper being constructed" << std::endl;
    }
    ~FuselageWrapper()
    {
        delete fusPtr;
        std::cout << "FuselageWrapper being deconstructed (deleted fusPtr)" << std::endl;
    }
};

// New UDT 4

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


struct GcWrapper
{
    GuitarCollector* gcPtr = nullptr;
    GcWrapper( GuitarCollector* ptrToGuitarCollector ) : gcPtr(ptrToGuitarCollector)
    {
        std::cout <<  "GcWrapper being constructed" << std::endl;
    }
    ~GcWrapper()
    {
        delete gcPtr;
        std::cout << "GcWrapper being deconstructed (deleted gcPtr)" << std::endl;
    }
};

// New UDT 5

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

struct CopWrapper
{
    CoreOfPlane* copPtr = nullptr;
    CopWrapper( CoreOfPlane* ptrToCop ) : copPtr(ptrToCop)
    {
       std::cout << "CopWrapper being constructed" << std::endl; 
    }
    ~CopWrapper()
    {
        delete copPtr;
        std::cout << "CopWrapper being deconstructed (deleted copPtr)" << std::endl;
        
    }
};

int main()
{
    GuitarWrapper gtrWrapper( new Guitar() );
    Guitar::Strings eball;
    gtrWrapper.gtrPtr->playNote("F");
    gtrWrapper.gtrPtr->tune(.04f);
    gtrWrapper.gtrPtr->makePercussiveNoise();
    gtrWrapper.gtrPtr->increaseVolume(50);
    gtrWrapper.gtrPtr->displayVolumeLevel();
    eball.bend("A", false);
    eball.slide("G", "A");
    eball.snap();
    eball.displayCurrentPitchST();
    std::cout << "Current pitch ST: " << eball.currentPitchST << std::endl;
    std::cout << "Current volume level is: " << gtrWrapper.gtrPtr->volumeLevel << std::endl;

    EnginesWrapper egWrapper( new Engines() );
    Engines::Turbines tb;
    egWrapper.egPtr->engageThrust(tb, true);
    egWrapper.egPtr->increasePower(40);
    egWrapper.egPtr->controlSpeed();
    egWrapper.egPtr->displaySize();
    tb.increaseThrustLevel(20);
    tb.increaseSpeed(20);
    tb.increasePressure(40);
    tb.releaseFuel(10);
    tb.displayMaterial();
    std::cout << "Size of engines: " << egWrapper.egPtr->size << std::endl;
    std::cout << "Fuel released: " << tb.fuelReleased << std::endl;

    FuselageWrapper fusWrapper( new Fuselage() );
    fusWrapper.fusPtr->encloseCabin();
    fusWrapper.fusPtr->supportWingsAndTail();
    fusWrapper.fusPtr->maintainInternalPressure();
    fusWrapper.fusPtr->receivePassengers(10);
    fusWrapper.fusPtr->displayCapacity();
    std::cout << "The fuselage can hold up to " << fusWrapper.fusPtr->capacity << " passengers" << std::endl;

    GcWrapper gcWrapper( new GuitarCollector() );
    gcWrapper.gcPtr->raiseMultipleVolumes();
    gcWrapper.gcPtr->tuneAll();
    
    CopWrapper copWrapper( new CoreOfPlane() );
    copWrapper.copPtr->adjustPressures();
    copWrapper.copPtr->startUp();
     
    std::cout << "good to go!" << std::endl;
}
