/*
  ==============================================================================

    DrumPadComponent.cpp
    Created: 4 Apr 2016 2:00:50pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "DrumPadComponent.h"
#include "MixerComponent.h"
#include "SampleInfo.h"

DrumPadComponent::~DrumPadComponent(){}
DrumPadComponent::DrumPadComponent(int _padId, int _sampleId, MixerComponent* _mixer)
{
    mixer = _mixer;
    padId = _padId;
    sampleId = _sampleId;
    Image image = SampleInfo::getInstance()->getImageBySampleId(_sampleId);
    padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);
}

void DrumPadComponent::buttonClicked(juce::Button *button){}
void DrumPadComponent::buttonStateChanged(Button* button)
{
    if (Button::ButtonState::buttonOver) {
        mixer->playSample(padId);
    }
}

void DrumPadComponent::resized()
{
    padButton.centreWithSize(getWidth(), getHeight());
}