/*
  ==============================================================================

    HeaderComponent.cpp
    Created: 3 Apr 2016 3:53:59pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "HeaderComponent.h"

HeaderComponent::~HeaderComponent(){}
HeaderComponent::HeaderComponent()
{
    Image image = ImageCache::getFromMemory (BinaryData::_29_png, BinaryData::_29_pngSize);

    drumButton.addListener(this);
    drumButton.setEnabled(true);
    drumButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white, 0.5f);
    addAndMakeVisible(drumButton);
    mixerButton.addListener(this);
    mixerButton.setEnabled(true);
    mixerButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white, 0.5f);
    addAndMakeVisible(mixerButton);
    settingsButton.addListener(this);
    settingsButton.setEnabled(true);
    settingsButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white, 0.5f);
    addAndMakeVisible(settingsButton);
    
    logo.setImage(image, RectanglePlacement::Flags::centred);
    addAndMakeVisible(logo);
}

void HeaderComponent::resized()
{
    Rectangle<int> bounds = getLocalBounds();
    float headerWidth = bounds.getWidth();
    float buttonWidth = headerWidth/6.0f;
    float headerHeight = bounds.getHeight();
    drumButton.setBounds(0.0f, 0.0f, buttonWidth, headerHeight);
    mixerButton.setBounds(buttonWidth, 0.0f, buttonWidth, headerHeight);
    settingsButton.setBounds(2.0f*buttonWidth, 0.0f, buttonWidth, headerHeight);
    logo.setBounds(headerWidth*0.5f, 0, headerWidth*0.5f, headerHeight);
}

void HeaderComponent::buttonClicked(juce::Button *button)
{
    if (button == &drumButton) {
        Logger::writeToLog("yeah");
    } else if (button == &mixerButton) {
        Logger::writeToLog("yeah");
    } else if (button == &settingsButton) {
        Logger::writeToLog("yeah");
    }
}