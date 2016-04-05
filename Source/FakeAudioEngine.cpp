/*
  ==============================================================================

    FakeAudioEngine.cpp
    Created: 5 Apr 2016 11:54:09am
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "FakeAudioEngine.h"
#include "../JuceLibraryCode/JuceHeader.h"

FakeAudioEngine::FakeAudioEngine(){}
FakeAudioEngine::~FakeAudioEngine(){}

void FakeAudioEngine::playSamples(int sampleId, float volume)
{
    Logger::writeToLog("PlaySample:" + String(sampleId) + "at Volume:" + String(volume));
}