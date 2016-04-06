/*
  ==============================================================================

    DrumPadComponent.cpp
    Created: 4 Apr 2016 2:00:50pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "DrumPadComponent.h"
#include "MixerComponent.h"

DrumPadComponent::~DrumPadComponent(){}
DrumPadComponent::DrumPadComponent(int _padId, int _sampleId, MixerComponent* _mixer)
{
    mixer = _mixer;
    padId = _padId;
    sampleLabel = new Label();
    sampleLabel->setJustificationType(Justification::centred);
    setSample(_sampleId);
    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);
    addAndMakeVisible(sampleLabel);
}

DrumPadComponent::DrumPadComponent(sampleInfoS infoSample)
{
    mixer = nullptr;
    padId = 0;
    sampleId = infoSample.sampleId;
    typeCategory = infoSample.type;
    sampleLabel = new Label();
    sampleLabel->setJustificationType(Justification::centred);
    
    padButton.setImages(false, true, true, infoSample.image, 1.0f, Colours::transparentBlack,
                        infoSample.image, 1.0f, Colours::white, infoSample.image, 1.0f, Colours::white);
    
    sampleLabel->setText(infoSample.name, NotificationType::dontSendNotification);

    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);
    addAndMakeVisible(sampleLabel);
}

void DrumPadComponent::setSample(int _sampleId)
{
    sampleId = _sampleId;
    sampleInfoS infoSample = SampleInfo::getInstance()->getInfoForSampleId(sampleId);
    typeCategory = infoSample.type;
    padButton.setImages(false, true, true, infoSample.image, 1.0f, Colours::transparentBlack,
                        infoSample.image, 1.0f, Colours::white, infoSample.image, 1.0f, Colours::white);
    
    sampleLabel->setText(infoSample.name, NotificationType::dontSendNotification);
}

void DrumPadComponent::addListener(DrumPadComponent::Listener *_listener)
{
    listener = _listener;
}

void DrumPadComponent::buttonClicked(Button* button)
{
    if (!padId && sampleId && button == &padButton && mixer)
        mixer->playSample(sampleId, 50.0f);
    
    if (listener)
        listener->drumPadWasClicked(this);
}

void DrumPadComponent::buttonStateChanged(Button* button)
{
    if (button == &padButton && padId && button->getState() == Button::ButtonState::buttonDown && mixer)
        mixer->playSample(padId);
    
    if (listener)
        listener->drumPadWasTouchedDown(this);
}

void DrumPadComponent::resized()
{
    Logger::writeToLog("Width:" + String(getWidth()) + " Height:" + String(getHeight()));
    sampleLabel->setFont(Font(getWidth()*0.12f));
    padButton.setBounds(0, getHeight()*0.04f, getWidth(), getHeight()*0.70f);
    sampleLabel->setBounds(0, getHeight()*0.75f, getWidth(), getHeight()*0.25f);
}