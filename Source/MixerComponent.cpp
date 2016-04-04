/*
  ==============================================================================

    MixerComponent.cpp
    Created: 4 Apr 2016 5:43:04pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "MixerComponent.h"
#include "MixerPadComponent.h"

MixerComponent::~MixerComponent(){}
MixerComponent::MixerComponent()
{
    for (int i = 0; i < 10; ++i) {
        auto pad = new MixerPadComponent();
        padsMixer.push_back(pad);
        addAndMakeVisible(pad);
    }
}

void MixerComponent::resized()
{
    int padsNumber = (int)padsMixer.size();
    float spaceBetween = 5.0f;
    float padWidth = (getWidth() - spaceBetween * (padsNumber + 1))/padsNumber;
    int i = 0;
    for (auto pad : padsMixer) {
        pad->setBounds(spaceBetween*(i + 1) + padWidth*i, 0, padWidth, getHeight() - 20.0f);
        ++i;
    }
}
