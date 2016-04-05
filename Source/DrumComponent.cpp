/*
  ==============================================================================

    DrumComponent.cpp
    Created: 4 Apr 2016 2:00:33pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "DrumComponent.h"
#include "DrumPadComponent.h"
#include "AudioEngineGuiInterface.h"
#include "MixerComponent.h"

#define         kMaxNumberOfPads     10

DrumComponent::~DrumComponent(){}
DrumComponent::DrumComponent(MixerComponent* _mixer)
{
    mixer = _mixer;
    for (int i = 0; i < kMaxNumberOfPads; ++i) {
        addPad((i % 10) + 1);
    }
}

void DrumComponent::resized()
{
    int i = 0;
    int j = 0;
    int padsNumberPerLine = 5;
    float padWidth = getWidth()/(padsNumberPerLine*1.5f + 0.5f);
    for (auto pad : padsDrum) {
        pad->setBounds(padWidth*(1.5f*i + 0.5f), padWidth*(0.6f + j)*2.0f, padWidth, padWidth);
        ++i;
        if (i > 4) {
            ++j;
            i = 0;
        }
    }
}

void DrumComponent::changeSampleToPadId(int sampleId, int padId)
{
    if (DrumPadComponent* pad = getPadByPadId(padId))
        pad->setSample(sampleId);
}
DrumPadComponent* DrumComponent::getPadByPadId(int padId)
{
    for (auto pad : padsDrum)
        if (padId == pad->getPadId())
            return pad;
    
    return nullptr;
}

int DrumComponent::addPad(int sampleId)
{
    int drumSize = (int)padsDrum.size();
    if (drumSize < kMaxNumberOfPads) {
        int padId = drumSize + 1;
        int sampleId = (drumSize % 10) + 1;
        auto pad = new DrumPadComponent(padId, sampleId, mixer);
        padsDrum.push_back(pad);
        addAndMakeVisible(pad);
        mixer->addPad(padId, sampleId);
    }
    return drumSize;
}
