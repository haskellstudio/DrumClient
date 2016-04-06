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
DrumPadComponent::DrumPadComponent(int _padId, int _sampleId, MixerComponent* _mixer, bool _isDraggable)
{
    mixer = _mixer;
    isDraggable = _isDraggable;
    padId = _padId;
    sampleLabel = new Label();
    sampleLabel->setJustificationType(Justification::centred);
    setSample(_sampleId);
    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);
    addAndMakeVisible(sampleLabel);
}

DrumPadComponent::DrumPadComponent(sampleInfoS infoSample, bool _isDraggable)
{
    mixer = nullptr;
    isDraggable = _isDraggable;
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

bool DrumPadComponent::hitTest (int x, int y)
{
    if (isDraggable && isDragging) {
        float dx = x - getWidth()*0.5f;
        float dy = y - getHeight()*0.5f;
        setTopLeftPosition(getX() + dx*0.5f, getY() + dy*0.5f);
    }
    return true;
}

void DrumPadComponent::addListener(DrumPadComponent::Listener *_listener)
{
    listener = _listener;
}

void DrumPadComponent::buttonClicked(Button* button)
{
    if (isDragging) {
        isDragging = false;
        Image image = padButton.getNormalImage();
        padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f,
                            Colours::white, image, 1.0f, Colours::white);
        if (Component* newParentComponent = getComponentAt(getPosition().x + getWidth()*0.5f, getPosition().y + getHeight()*0.5f)) {
            setTopLeftPosition(getPosition().x - newParentComponent->getPosition().x, getPosition().y - newParentComponent->getPosition().y);
            newParentComponent->addAndMakeVisible(this);
        }
    }

    if (!padId && sampleId && button == &padButton && mixer) {
        mixer->playSample(sampleId, 50.0f);
    }
    
    if (listener)
        listener->drumPadWasClicked(this);
}

void DrumPadComponent::buttonStateChanged(Button* button)
{
    if (button->getState() == Button::ButtonState::buttonDown && isDraggable) {
        isDragging = true;
        Image image = padButton.getNormalImage();
        padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f,
                            Colours::transparentBlack, image, 1.0f, Colours::transparentBlack);
        Logger::writeToLog("Yeah " + String(firstTouch.x) + " " + String(firstTouch.y));
        Point<int> convertedPosition = getPosition();
        Component* parent = getParentComponent();
        while (parent) {
            convertedPosition += parent->getPosition();
            parent = parent->getParentComponent();
        }
        setTopLeftPosition(convertedPosition);
        getPeer()->getComponent().addAndMakeVisible(this);
    }
    
    if (button == &padButton && padId && button->getState() == Button::ButtonState::buttonDown && mixer)
        mixer->playSample(padId);
    
    if (listener)
        listener->drumPadWasTouchedDown(this);
}


void DrumPadComponent::resized()
{
    Logger::writeToLog("Width:" + String(getWidth()) + " Height:" + String(getHeight()));
    sampleLabel->setFont(Font((getHeight() + getWidth())*0.06f));
    padButton.setBounds(0, getHeight()*0.04f, getWidth(), getHeight()*0.70f);
    sampleLabel->setBounds(0, getHeight()*0.75f, getWidth(), getHeight()*0.25f);
}