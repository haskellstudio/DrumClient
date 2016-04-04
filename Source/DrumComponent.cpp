/*
  ==============================================================================

    DrumComponent.cpp
    Created: 4 Apr 2016 2:00:33pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "DrumComponent.h"
#include "DrumPadComponent.h"

DrumComponent::~DrumComponent(){}
DrumComponent::DrumComponent()
{
    pad1 = new DrumPadComponent(1);
    addAndMakeVisible(pad1);
}

void DrumComponent::resized()
{
    pad1->setBounds(getWidth()*0.2f, getHeight()*0.2f, getWidth()*0.2f, getWidth()*0.4f);
}
