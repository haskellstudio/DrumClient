/*
  ==============================================================================

    MixerComponent.h
    Created: 4 Apr 2016 5:43:04pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef MIXERCOMPONENT_H_INCLUDED
#define MIXERCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MixerComponent : public Component
{
public:
    MixerComponent();
    ~MixerComponent();
    
    void resized() override;
private:
};


#endif  // MIXERCOMPONENT_H_INCLUDED
