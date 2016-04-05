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
    sampleLabel = new Label();
    sampleLabel->setFont(Font(18.0f));
    sampleLabel->setJustificationType(Justification::centred);
    setSample(_sampleId);
    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);
    addAndMakeVisible(sampleLabel);
}

void DrumPadComponent::setSample(int _sampleId)
{
    sampleId = _sampleId;
    Image image = SampleInfo::getInstance()->getImageBySampleId(_sampleId);
    padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    sampleLabel->setText(SampleInfo::getInstance()->getNameForSampleId(_sampleId), NotificationType::dontSendNotification);
}

void DrumPadComponent::buttonClicked(Button* button)
{
    if (!padId && sampleId && button == &padButton) {
        mixer->playSample(sampleId, 50.0f);
    }
}

void DrumPadComponent::buttonStateChanged(Button* button)
{
    if (button == &padButton && padId && button->getState() == Button::ButtonState::buttonOver) {
        mixer->playSample(padId);
    }
}

void DrumPadComponent::resized()
{
    padButton.setBounds(0, getHeight()*0.04f, getWidth(), getHeight()*0.8f);
    sampleLabel->setBounds(0, getHeight()*0.84f, getWidth(), getHeight()*0.16f);
}