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

private:
    int padId;
    int sampleId;
    ImageButton padButton;
    MixerComponent* mixer;
    
};



#endif  // DRUMPADCOMPONENT_H_INCLUDED
