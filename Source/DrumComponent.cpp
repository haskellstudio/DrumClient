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
    for (int i = 0; i < 14; ++i) {
        auto pad = new DrumPadComponent((i % 10) + 1);
        pads.push_back(pad);
        addAndMakeVisible(pad);
        
    }
}

void DrumComponent::resized()
{
    float i = 0.0f;
    float j = 0.0f;
    for (auto pad : pads) {
        pad->setBounds(getWidth()*(0.1f + i), getHeight()*(0.1f + j), getWidth()*0.1f, getWidth()*0.1f);
        i += 0.15f;
        if (i > 0.7f) {
            j += 0.15f;
            i = 0;
        }
    }
}
