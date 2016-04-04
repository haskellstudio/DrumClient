/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "HeaderComponent.h"
#include "DrumComponent.h"

//==============================================================================
MainContentComponent::~MainContentComponent(){}
MainContentComponent::MainContentComponent()
{
    Rectangle<int> screenSize = Desktop::getInstance().getDisplays().getMainDisplay().userArea;

    header = new HeaderComponent();
    drum = new DrumComponent();
    addAndMakeVisible(header);
    addAndMakeVisible(drum);
    
    setSize (screenSize.getWidth(), screenSize.getHeight());
}


void MainContentComponent::resized()
{
    float width = getWidth();
    float height = getHeight();
    header->setBounds(0, 0, width, height*0.2f);
    drum->setBounds(width*0.3f, height*0.25f, width*0.7f, height*0.75f);
}
