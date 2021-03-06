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
#include "SampleInfo.h"

DrumComponent::~DrumComponent(){}
DrumComponent::DrumComponent(MixerComponent* _mixer)
{
    mixer = _mixer;
    for (int i = 0; i < kMaxNumberOfPads; ++i) {
        addPad(3*(i + 1));
    }

    NotificationCentre::getInstance()->addObserver(this, kDrumWasReleased);
    NotificationCentre::getInstance()->addObserver(this, kDrumKitHasChanged);
}

void DrumComponent::paint(juce::Graphics &g)
{
    g.fillAll(Colours::grey);
}

void DrumComponent::resized()
{
    int i = 0;
    int j = 0;
    int padsNumberPerLine = kMaxNumberOfPads/2;
    float padWidth = getWidth()/((padsNumberPerLine + 1)*1.5f + 0.5f);
    for (auto pad : padsDrum) {
        pad->setBounds(padWidth*(1.5f*(i + 0.5f) + 0.5f), getHeight()*0.46f + padWidth*(1.0f - 2.0f*float(1 - j)), padWidth, padWidth*1.4f);
        ++i;
        if (i > 4) {
            ++j;
            i = 0;
        }
    }
}

void DrumComponent::setDrumKit(String& drumKitName)
{
    auto drumKit = SampleInfo::getInstance()->getDrumKitByName(drumKitName);
    int i = 0;
    
    for (auto sample : drumKit)
        changeSampleToPad(sample, padsDrum[i++]);
}

void DrumComponent::drumPadWasReleasedIn(Point<int> position, int sampleId)
{
    Point<int> convertedPosition = position - getPosition();

    for (auto pad :padsDrum)
        if (pad->getBounds().contains(convertedPosition))
            changeSampleToPad(sampleId, pad);
}

void DrumComponent::changeSampleToPad(int sampleId, DrumPadComponent *pad)
{
    pad->setSample(sampleId);
    mixer->setSampleToPad(sampleId, pad->getPadId());
}

void DrumComponent::changeSampleToPadId(int sampleId, int padId)
{
    if (DrumPadComponent* pad = getPadByPadId(padId))
        changeSampleToPad(sampleId, pad);
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
        auto pad = new DrumPadComponent(padId, sampleId, mixer, true);
        padsDrum.push_back(pad);
        addAndMakeVisible(pad);
        mixer->addPad(padId, sampleId);
    }
    return drumSize;
}
