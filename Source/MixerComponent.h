/*
  ==============================================================================

    MixerComponent.h
    Created: 4 Apr 2016 5:43:04pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef MIXERCOMPONENT_H_INCLUDED
#define MIXERCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MixerPadComponent;
class AudioEngineGuiInterface;

class MixerComponent : public Component
{
public:
    MixerComponent(AudioEngineGuiInterface* _audioEngine);
    ~MixerComponent();

    AudioEngineGuiInterface* audioEngine;
    
    float getVolumeForPad(int padId);
    void resized() override;
    void paint(juce::Graphics &g) override;
    void addPad(int _padId, int _sampleId); /// return padId
    void setSampleToPad(int _sampleId, int _padId);
    MixerPadComponent* getPadById(int padId);
    void playSample(int padId);
    void playSample(int sampleId, float volume);
    
private:
    std::vector<MixerPadComponent*> padsMixer;
};


#endif  // MIXERCOMPONENT_H_INCLUDED
