/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "HeaderComponent.h"
#include "DrumComponent.h"
#include "MixerComponent.h"
#include "FakeAudioEngine.h"

//==============================================================================
MainContentComponent::~MainContentComponent(){}
MainContentComponent::MainContentComponent()
{
    audioEngine = new FakeAudioEngine();
    Rectangle<int> screenSize = Desktop::getInstance().getDisplays().getMainDisplay().userArea;

    header = new HeaderComponent();
    header->addHeaderListener(this);
    mixer = new MixerComponent(audioEngine);
    drum = new DrumComponent(mixer);
    addAndMakeVisible(header);
    addAndMakeVisible(drum);
    addChildComponent(mixer);
    mixer->setVisible(false);
    
    setSize (screenSize.getWidth(), screenSize.getHeight());
}


void MainContentComponent::resized()
{
    float width = getWidth();
    float height = getHeight();
    Rectangle<int> focusArea(width*0.25f, height*0.25f, width*0.7f, height*0.75f);
    header->setBounds(0, 0, width, height*0.2f);
    drum->setBounds(focusArea);
    mixer->setBounds(focusArea);
    
}

void MainContentComponent::headerChanged(HeaderComponent::HeaderButtons headerButton)
{
    drum->setVisible(HeaderComponent::HeaderButtons::DRUM == headerButton);
    mixer->setVisible(HeaderComponent::HeaderButtons::MIXER == headerButton);
//    settings->setVisible(HeaderComponent::HeaderButtons::SETTINGS == headerButton);
}


