/*
  ==============================================================================

    MixerPadComponent.cpp
    Created: 4 Apr 2016 7:07:06pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "MixerPadComponent.h"
#include "MixerComponent.h"

void MixerPadComponent::sliderValueChanged (Slider* slider) {}

MixerPadComponent::~MixerPadComponent(){}
MixerPadComponent::MixerPadComponent(int _padId, int _sampleId, MixerComponent* _mixer)
{
    mixer = _mixer;
    padId = _padId;
    sampleId = _sampleId;
    addAndMakeVisible (volumeSlider);
    volumeSlider.setRange (0.0, 100.0);
    volumeSlider.addListener (this);
    volumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

void MixerPadComponent::resized()
{
    volumeSlider.setBounds(0, getHeight()*0.35f, getWidth(), getHeight()*0.4f);
}
void MixerPadComponent::buttonClicked(Button* button)
{
    //// if è il pulsante giusto
    mixer->playSample(sampleId, getVolume());
}
