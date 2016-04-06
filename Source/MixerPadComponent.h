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

class MixerComponent;

class MixerPadComponent : public Component,
                          public Slider::Listener,
                          public Button::Listener
{
public:
    MixerPadComponent(int _padId, int _sampleId, MixerComponent* _mixer);
    ~MixerPadComponent();
    
    void resized() override;
    void buttonClicked(Button*) override {};
    void buttonStateChanged (Button*) override;
    void sliderValueChanged (Slider* slider) override;

    float getVolume() {return volumeSlider.getValue();};
    int getPadId() {return padId;};
    int getSampleId() {return sampleId;};
    void setSample(int _sampleId);

private:
    Slider volumeSlider;
    ImageButton playButton;
    Label sampleLabel;
    MixerComponent* mixer;
    int padId;
    int sampleId;
};


#endif  // MIXERPADCOMPONENT_H_INCLUDED
