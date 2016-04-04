/*
  ==============================================================================

    MixerPadComponent.h
    Created: 4 Apr 2016 7:07:06pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef MIXERPADCOMPONENT_H_INCLUDED
#define MIXERPADCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MixerPadComponent : public Component,
                          public Slider::Listener,
                          public Button::Listener
{
public:
    MixerPadComponent();
    ~MixerPadComponent();
    
    void resized() override;
    void buttonClicked(Button* button) override;
    void sliderValueChanged (Slider* slider) override;

private:
    Slider volumeSlider;
};


#endif  // MIXERPADCOMPONENT_H_INCLUDED
