/*
  ==============================================================================

    DrumPadComponent.h
    Created: 4 Apr 2016 2:00:50pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef DRUMPADCOMPONENT_H_INCLUDED
#define DRUMPADCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SampleInfo.h"

class MixerComponent;

class DrumPadComponent : public Component,
                         public Button::Listener
{
public:

    DrumPadComponent(int _padId, int _sampleId, MixerComponent* _mixer);
    DrumPadComponent(sampleInfoS infoSample);
    ~DrumPadComponent();
    
    void resized() override;
    void buttonClicked(Button* button) override;
    void buttonStateChanged (Button*) override;
    int getPadId() {return padId;};
    int getSampleId() {return sampleId;};
    PadType getCategoryType() {return typeCategory;};
    void setSample(int _sampleId);

    class Listener
    {
    public:
        virtual ~Listener() {};
        virtual void drumPadWasClicked(DrumPadComponent* sender) = 0;
        virtual void drumPadWasTouchedDown(DrumPadComponent* sender) = 0;
    };
    void addListener(DrumPadComponent::Listener* _listener);
    DrumPadComponent::Listener* listener = nullptr;
    
private:
    int padId = 0;
    int sampleId = 0;
    ImageButton padButton;
    MixerComponent* mixer;
    Label* sampleLabel;
    PadType typeCategory;
};



#endif  // DRUMPADCOMPONENT_H_INCLUDED
