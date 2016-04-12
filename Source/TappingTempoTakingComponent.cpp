/*
  ==============================================================================

    TappingTempoTakingComponent.cpp
    Created: 11 Apr 2016 7:26:19pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "TappingTempoTakingComponent.h"
#include <sys/time.h>

TappingTempoTakingComponent::~TappingTempoTakingComponent()
{}
TappingTempoTakingComponent::TappingTempoTakingComponent()
{
    addAndMakeVisible(tempoTakingByButton);
    tempoTakingByButton.setButtonText("Yeah");
    tempoTakingByButton.addListener(this);
    tempoTakingByButton.setEnabled(true);
}

void TappingTempoTakingComponent::paint(Graphics& g)
{
    g.setColour(Colours::darkgrey);
    g.fillRoundedRectangle(0.0f, 0.0f, getWidth(), getHeight(), getWidth()*0.1f);
    g.setColour(Colours::grey);
    g.setFont(28.0f);
    g.drawText("Tap", 0.0f, 0.0f, getWidth(), getHeight(), Justification::centred);
}

void TappingTempoTakingComponent::resized()
{
    tempoTakingByButton.setBounds(0, 0, getWidth(), getHeight());
}

void TappingTempoTakingComponent::buttonStateChanged(Button* button)
{
    if (listener)
        Logger::writeToLog("yeah");
    
    
    if (button == &tempoTakingByButton && Button::ButtonState::buttonDown == button->getState() && listener) {
        struct timeval tp;
        gettimeofday(&tp, NULL);
        long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        if (-1 != lastTapTime && (ms - lastTapTime) < 4000) {
            listener->wasTappedWithTempo((60.0f * 1000.0f) / (ms - lastTapTime));
        }
        lastTapTime = ms;
    }
}


