#include <iostream>
#include "Guitar.h"

Guitar::Guitar() :
numStrings(6),
numFrets(22),
volumeLevel(40),
brand("Gibson"),
material("Spruce Wood"),
inTune(false)
{
    std::cout << "Guitar being constructed!" << std::endl;
}

Guitar::~Guitar()
{
    std::cout << "Guitar being deconstructed" << std::endl;
}

Guitar::Strings::Strings() :
lowEStringGauge(.040f),
dStringGauge(.10f),
brand("Ernie Ball"),
sku("2229"),
material("Nickel"),
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
bool Guitar::Strings::snap() const
{
    return true;
}

void Guitar::Strings::displayCurrentPitchST() const
{
    std::cout << "Current pitch ST: " << this->currentPitchST << std::endl;
}

bool Guitar::playNote(const std::string whichNote)
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

void Guitar::displayVolumeLevel() const
{
    std::cout << "Current volume level is: " << this->volumeLevel << std::endl;
}

