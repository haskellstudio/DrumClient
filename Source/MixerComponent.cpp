/*
  ==============================================================================

    MixerComponent.cpp
    Created: 4 Apr 2016 5:43:04pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "MixerComponent.h"
#include "MixerPadComponent.h"
#include "AudioEngineGuiInterface.h"

MixerComponent::~MixerComponent(){}
MixerComponent::MixerComponent(AudioEngineGuiInterface* _audioEngine)
{
    audioEngine = _audioEngine;
}

void MixerComponent::resized()
{
    int padsNumber = (int)padsMixer.size();
    float spaceBetween = 5.0f;
    float padWidth = (getWidth() - spaceBetween * (padsNumber + 1))/padsNumber;
    int i = 0;
    for (auto pad : padsMixer) {
        pad->setBounds(spaceBetween*(i + 1) + padWidth*i, 0, padWidth, getHeight() - 20.0f);
        ++i;
    }
}

void MixerComponent::addPad(int padId, int sampleId)
{
    auto pad = new MixerPadComponent(padId, sampleId, this);
    padsMixer.push_back(pad);
    addAndMakeVisible(pad);
}

MixerPadComponent* MixerComponent::getPadById(int padId)
{
    for (auto pad : padsMixer)
        if (padId == pad->getPadId())
            return pad;
    
    return nullptr;
}

void MixerComponent::playSample(int padId)
{
    if (auto pad = getPadById(padId))
        playSample(pad->getSampleId(), pad->getVolume());
}

void MixerComponent::playSample(int sampleId, float volume)
{
    audioEngine->playSamples(sampleId, volume);
}
