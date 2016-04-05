/*
  ==============================================================================

    FakeAudioEngine.h
    Created: 5 Apr 2016 11:54:09am
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef FAKEAUDIOENGINE_H_INCLUDED
#define FAKEAUDIOENGINE_H_INCLUDED

#include "AudioEngineGuiInterface.h"

class FakeAudioEngine : public AudioEngineGuiInterface
{
public:
    FakeAudioEngine();
    ~FakeAudioEngine();
    
    void playSamples(int sampleId, float volume) override;
private:
};

#endif  // FAKEAUDIOENGINE_H_INCLUDED
