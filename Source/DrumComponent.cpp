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
    for (int i = 0; i < 10; ++i) {
        auto pad = new DrumPadComponent((i % 10) + 1);
        padsDrum.push_back(pad);
        addAndMakeVisible(pad);
        
    }
}

void DrumComponent::resized()
{
    int i = 0;
    int j = 0;
    int padsNumberPerLine = 5;
    float padWidth = getWidth()/(padsNumberPerLine*1.5f + 0.5f);
    for (auto pad : padsDrum) {
        pad->setBounds(padWidth*(1.5f*i + 0.5f), padWidth*(0.6f + j)*2.0f, padWidth, padWidth);
        ++i;
        if (i > 4) {
            ++j;
            i = 0;
        }
    }
}
