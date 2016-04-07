/*
  ==============================================================================

    MixerPadComponent.cpp
    Created: 4 Apr 2016 7:07:06pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "MixerPadComponent.h"
#include "MixerComponent.h"
#include "SampleInfo.h"

void MixerPadComponent::sliderValueChanged (Slider* slider) {}

MixerPadComponent::~MixerPadComponent(){}
MixerPadComponent::MixerPadComponent(int _padId, int _sampleId, MixerComponent* _mixer)
{
    mixer = _mixer;
    padId = _padId;
    setSample(_sampleId);
    addAndMakeVisible (volumeSlider, 100);
    volumeSlider.setRange (0.0, 100.0);
    volumeSlider.setValue(50.0f);
    volumeSlider.addListener (this);
    volumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(sampleLabel);
    sampleLabel.setJustificationType(Justification::centred);
    sampleLabel.setFont(Font(16.0f));
    addAndMakeVisible(playButton);
    playButton.addListener(this);
    playButton.setEnabled(true);
    Image image = ImageCache::getFromMemory (BinaryData::playMixer_png, BinaryData::playMixer_pngSize);;
    playButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
}

void MixerPadComponent::setSample(int _sampleId)
{
    sampleId = _sampleId;
    sampleLabel.setText(SampleInfo::getInstance()->getNameForSampleId(_sampleId), NotificationType::dontSendNotification);
}

void MixerPadComponent::resized()
{
    float width = getWidth();
    float height = getHeight();
    volumeSlider.setBounds(0, height*0.2f, width, height*0.55f);
    sampleLabel.setBounds(0, height*0.72, width, height*0.14f);
    playButton.setBounds(0, height*0.83f, width, height*0.1f);
}
void MixerPadComponent::buttonStateChanged(juce::Button *button)
{
    if (button == &playButton && Button::ButtonState::buttonDown == button->getState())
        mixer->playSample(sampleId, getVolume());
}
