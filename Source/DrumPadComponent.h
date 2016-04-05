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

class MixerComponent;

class DrumPadComponent : public Component,
                         public Button::Listener
{
public:

    DrumPadComponent(int _padId, int _sampleId, MixerComponent* _mixer);
    ~DrumPadComponent();
    
    void resized() override;
    void buttonClicked(Button* button) override;
    void buttonStateChanged (Button*) override;
    int getPadId() {return padId;};
    void setSample(int _sampleId);
private:
    int padId = 0;
    int sampleId = 0;
    ImageButton padButton;
    MixerComponent* mixer;
    Label* sampleLabel;
    
};



#endif  // DRUMPADCOMPONENT_H_INCLUDED
