#pragma once
#include "LeakedObjectDetector.h"

struct Guitar
{
    int numStrings;
    int numFrets;
    int volumeLevel;
    std::string brand;
    std::string material;
    bool inTune;

    struct Strings
    {
        float lowEStringGauge; 
        float dStringGauge;
        std::string brand;
        std::string sku;
        std::string material;
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