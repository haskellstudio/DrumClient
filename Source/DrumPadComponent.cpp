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
    sampleLabel = new Label();
    sampleLabel->setJustificationType(Justification::centred);
    init(_padId, _sampleId, _mixer, _isDraggable);
}

DrumPadComponent::DrumPadComponent(sampleInfoS infoSample, bool _isDraggable)
{
    sampleLabel = new Label();
    sampleLabel->setJustificationType(Justification::centred);
    init(infoSample, _isDraggable);
}

void DrumPadComponent::init(int _padId, int _sampleId, MixerComponent* _mixer, bool _isDraggable)
{
    mixer = _mixer;
    isDraggable = _isDraggable;
    padId = _padId;
    setSample(_sampleId);
    addComponentsAndInit();

}
void DrumPadComponent::init(sampleInfoS infoSample, bool _isDraggable)
{
    mixer = nullptr;
    isDraggable = _isDraggable;
    padId = 0;
    sampleId = infoSample.sampleId;
    typeCategory = infoSample.type;
    
    padButton.setImages(false, true, true, infoSample.image, 1.0f, Colours::transparentBlack,
                        infoSample.image, 1.0f, Colours::white, infoSample.image, 1.0f, Colours::white);
    sampleLabel->setText(infoSample.name, NotificationType::dontSendNotification);
    addComponentsAndInit();
}

void DrumPadComponent::addComponentsAndInit()
{
    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);
    addAndMakeVisible(sampleLabel);
    firstHitTestPoint.x = -1;
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
    if (isDraggable && padButton.getState() == Button::ButtonState::buttonDown) {
        if (isDragging) {
            float dx = x - getWidth()*0.5f;
            float dy = y - getHeight()*0.5f;
            float newX = getX() + dx*0.5f;
            float newY = getY() + dy*0.5f;
            if (! padId || ((getWidth()*0.5f < newX && newX < (getParentComponent()->getWidth() - getWidth()*0.5f)) &&
                (getHeight()*0.5f < newY && newY < (getParentComponent()->getHeight() - getHeight()*0.5f)))) {
                setTopLeftPosition(newX, newY);
            }
        } else if (firstHitTestPoint.x == -1) {
            firstHitTestPoint.x = x;
            firstHitTestPoint.y = y;
        } else {
            float dx = x - firstHitTestPoint.x;
            float dy = y - firstHitTestPoint.y;
            float distCenterX = x - getWidth()*0.5f;
            float distCenterY = y - getHeight()*0.5f;
            float distFromFirstPoint = sqrt(dx*dx + dy*dy);
            if (distFromFirstPoint > getWidth()*0.3f ||  (distFromFirstPoint > getWidth()*0.15f &&
                                                          (abs(distCenterX) > getWidth()*0.47f || abs(distCenterY) > getHeight()*0.48f))) {
                startDragging();
            }
        }
    }
    return true;
}

void DrumPadComponent::buttonClicked(Button* button)
{
    firstHitTestPoint.x = -1;

    if (isDragging)
        stopDragging();

    if (! isBelongingToDrum() && ! isCategoryItem() && button == &padButton && mixer)
        mixer->playSample(sampleId, 50.0f);
    
    if (listener)
        listener->drumPadWasClicked(this);
}

void DrumPadComponent::buttonStateChanged(Button* button)
{
    if (button == &padButton && isBelongingToDrum() && button->getState() == Button::ButtonState::buttonDown && mixer)
        mixer->playSample(padId);
    
    if (listener)
        listener->drumPadWasTouchedDown(this);
}

void DrumPadComponent::stopDragging()
{
    isDragging = false;
    Image image = padButton.getNormalImage();
    padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f,
                        Colours::white, image, 1.0f, Colours::white);
    //        if (Component* newParentComponent = getComponentAt(getWidth()*0.5f, getHeight()*0.5f)) {
    //            setTopLeftPosition(getPosition().x - newParentComponent->getPosition().x, getPosition().y - newParentComponent->getPosition().y);
    //            newParentComponent->addAndMakeVisible(this);
    //        }
    if (isBelongingToDrum())
    {
        auto parent = getParentComponent();
        parent->removeChildComponent(this);
        parent->addAndMakeVisible(this, 0);
    }

}

void DrumPadComponent::startDragging()
{
    isDragging = true;
    Image image = padButton.getNormalImage();
    padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f,
                        Colours::transparentBlack, image, 1.0f, Colours::transparentBlack);

    if (isBelongingToDrum())
    {
        auto parent = getParentComponent();
        parent->removeChildComponent(this);
        parent->addAndMakeVisible(this, 100);
    }
    else
    {
        Point<int> convertedPosition = getPosition();
        Component* parent = getParentComponent();
        while (parent) {
            convertedPosition += parent->getPosition();
            parent = parent->getParentComponent();
        }
        setTopLeftPosition(convertedPosition);
        getPeer()->getComponent().addAndMakeVisible(this);
    }
}

void DrumPadComponent::resized()
{
    Logger::writeToLog("Width:" + String(getWidth()) + " Height:" + String(getHeight()));
    sampleLabel->setFont(Font((getHeight() + getWidth())*0.06f));
    padButton.setBounds(0, getHeight()*0.04f, getWidth(), getHeight()*0.70f);
    sampleLabel->setBounds(0, getHeight()*0.75f, getWidth(), getHeight()*0.25f);
}




