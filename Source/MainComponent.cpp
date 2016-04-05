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
#include "TablePadType.h"
#include "SampleInfo.h"

//==============================================================================
MainContentComponent::~MainContentComponent(){}
MainContentComponent::MainContentComponent()
{
    SampleInfo::getInstance();
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
    
    tableTypes = new TablePadType(mixer, screenSize.getWidth()*0.125f);
    addAndMakeVisible(tableTypes);
    
    setSize (screenSize.getWidth(), screenSize.getHeight());
}


void MainContentComponent::resized()
{
    float width = getWidth();
    float height = getHeight();
    float tableTypesWidth = width*0.125f;
    Rectangle<int> focusArea(tableTypesWidth, height*0.14f, width - tableTypesWidth, height*0.86f);
    header->setBounds(0, 0, width, height*0.14f);
    drum->setBounds(focusArea);
    mixer->setBounds(focusArea);
    tableTypes->setBounds(0, focusArea.getY(), tableTypesWidth, focusArea.getHeight());
}

void MainContentComponent::headerChanged(HeaderComponent::HeaderButtons headerButton)
{
    drum->setVisible(HeaderComponent::HeaderButtons::DRUM == headerButton);
    mixer->setVisible(HeaderComponent::HeaderButtons::MIXER == headerButton);
//    settings->setVisible(HeaderComponent::HeaderButtons::SETTINGS == headerButton);
}


