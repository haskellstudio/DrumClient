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
    
    Image image = ImageCache::getFromMemory (BinaryData::headerDrum_png, BinaryData::headerDrum_pngSize);
    drumButton.addListener(this);
    drumButton.setEnabled(true);
    drumButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    addAndMakeVisible(drumButton);
    
    image = ImageCache::getFromMemory (BinaryData::headerMixer_png, BinaryData::headerMixer_pngSize);
    mixerButton.addListener(this);
    mixerButton.setEnabled(true);
    mixerButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    addAndMakeVisible(mixerButton);
    
    image = ImageCache::getFromMemory (BinaryData::headerSettings_png, BinaryData::headerSettings_pngSize);
    settingsButton.addListener(this);
    settingsButton.setEnabled(true);
    settingsButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    addAndMakeVisible(settingsButton);

    image = ImageCache::getFromMemory (BinaryData::headerMetronome_png, BinaryData::headerMetronome_pngSize);
    metronomeButton.addListener(this);
    metronomeButton.setEnabled(true);
    metronomeButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    addAndMakeVisible(metronomeButton);

    image = ImageCache::getFromMemory (BinaryData::headerLogo_png, BinaryData::headerLogo_pngSize);
    logo.setImage(image, RectanglePlacement::Flags::centred);
    addAndMakeVisible(logo);
}

void HeaderComponent::paint(juce::Graphics &g)
{
    g.fillAll(Colours::darkgrey);
}

void HeaderComponent::resized()
{
    Rectangle<int> bounds = getLocalBounds();
    float headerWidth = bounds.getWidth();
    float buttonWidth = headerWidth/8.0f;
    float headerHeight = bounds.getHeight();
    drumButton.setBounds(0.0f, headerHeight*0.1f, buttonWidth, headerHeight*0.8f);
    mixerButton.setBounds(buttonWidth, headerHeight*0.1f, buttonWidth, headerHeight*0.8f);
    settingsButton.setBounds(2.0f*buttonWidth, headerHeight*0.1f, buttonWidth, headerHeight*0.8f);
    metronomeButton.setBounds(3.0f*buttonWidth, headerHeight*0.1f, buttonWidth, headerHeight*0.8f);
    logo.setBounds(headerWidth*0.5f, 0, headerWidth*0.5f, headerHeight);
}

void HeaderComponent::buttonClicked(juce::Button *button)
{
    if (listener) {
        if (button == &drumButton) {
            listener->headerChanged(HeaderButtons::DRUM);
        } else if (button == &mixerButton) {
            listener->headerChanged(HeaderButtons::MIXER);
        } else if (button == &settingsButton) {
            listener->headerChanged(HeaderButtons::SETTINGS);
        } else if (button == &metronomeButton) {
            listener->headerChanged(HeaderButtons::METRONOME);
        }
    }
}





