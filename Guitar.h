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
        bool snap() const;
        void displayCurrentPitchST() const;
    };

    Guitar();
    ~Guitar();

    bool playNote(const std::string whichNote);
    void tune(float CurrentCent);
    bool makePercussiveNoise();
    void increaseVolume(int targetVolume);   
    void displayVolumeLevel() const;

    JUCE_LEAK_DETECTOR(Guitar)
    
};
