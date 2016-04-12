/*
  ==============================================================================

    TappingTempoTakingComponent.h
    Created: 11 Apr 2016 7:26:19pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef TAPPINGTEMPOTAKINGCOMPONENT_H_INCLUDED
#define TAPPINGTEMPOTAKINGCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class TappingTempoTakingComponent : public Component,
                                    public Button::Listener
{
    
public:
    TappingTempoTakingComponent();
    ~TappingTempoTakingComponent();
    
    /// Component Overrides
    void resized() override;
    void paint(Graphics& g) override;

    /// Button::Listener Overrides
    void buttonClicked(Button* button) override {};
    void buttonStateChanged (Button* button) override;
    
    class Listener
    {
    public:
        virtual ~Listener() {};
        virtual void wasTappedWithTempo(int tempo) = 0;
    };
    
    void addListener(TappingTempoTakingComponent::Listener* _listener) {listener = _listener;};

private:
    TappingTempoTakingComponent::Listener* listener;
    TextButton tempoTakingByButton;
    long lastTapTime = -1;
};


#endif  // TAPPINGTEMPOTAKINGCOMPONENT_H_INCLUDED
