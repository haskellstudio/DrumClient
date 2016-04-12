/*
  ==============================================================================

    MetronomeComponent.h
    Created: 11 Apr 2016 7:25:36pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef METRONOMECOMPONENT_H_INCLUDED
#define METRONOMECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "TappingTempoTakingComponent.h"

class MetronomeComponent :  public Component,
                            public TappingTempoTakingComponent::Listener
{

public:
    MetronomeComponent();
    ~MetronomeComponent();
    
    void paint (Graphics& g) override;
    void resized() override;

    void wasTappedWithTempo(int tempo) override;

private:
    
    TappingTempoTakingComponent* tempoTaking;
    Label tempoLabel;
};


#endif  // METRONOMECOMPONENT_H_INCLUDED
