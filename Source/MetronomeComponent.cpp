/*
  ==============================================================================

    MetronomeComponent.cpp
    Created: 11 Apr 2016 7:25:36pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "MetronomeComponent.h"
#include "TappingTempoTakingComponent.h"

MetronomeComponent::~MetronomeComponent()
{}
MetronomeComponent::MetronomeComponent()
{
    tempoTaking = new TappingTempoTakingComponent();
    addAndMakeVisible(tempoTaking);
    tempoTaking->addListener(this);
    tempoLabel.setJustificationType(Justification::centred);
    tempoLabel.setText("120", NotificationType::dontSendNotification);
    addAndMakeVisible(tempoLabel);
}

void MetronomeComponent::resized()
{
    tempoTaking->setBounds(getWidth()*0.4, getHeight()*0.28f, getWidth()*0.2f, getWidth()*0.2f);
    tempoLabel.setBounds(getWidth()*0.4, getHeight()*0.06f, getWidth()*0.2f, getHeight()*0.22f);
}

void MetronomeComponent::wasTappedWithTempo(int tempo)
{
    tempoLabel.setText(String(tempo), NotificationType::dontSendNotification);
}


void MetronomeComponent::paint(Graphics& g)
{
    g.fillAll(Colours::grey);
}
