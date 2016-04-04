/*
  ==============================================================================

    MixerPadComponent.cpp
    Created: 4 Apr 2016 7:07:06pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "MixerPadComponent.h"

MixerPadComponent::~MixerPadComponent(){}
MixerPadComponent::MixerPadComponent()
{
    addAndMakeVisible (volumeSlider);
    volumeSlider.setRange (0.0, 100.0);
    volumeSlider.addListener (this);
    volumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);

}
void MixerPadComponent::sliderValueChanged (Slider* slider)
{
    if (slider == &volumeSlider) {
        Logger::writeToLog("SliderValue:" + String(slider->getValue()));
    }
}

void MixerPadComponent::resized()
{
    volumeSlider.setBounds(0, getHeight()*0.35f, getWidth(), getHeight()*0.4f);
}
void MixerPadComponent::buttonClicked(Button* button)
{
    
}
