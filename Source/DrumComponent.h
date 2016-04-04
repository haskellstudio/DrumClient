/*
  ==============================================================================

    DrumComponent.h
    Created: 4 Apr 2016 2:00:33pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef DRUMCOMPONENT_H_INCLUDED
#define DRUMCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class DrumPadComponent;

class DrumComponent : public Component
{
public:
    DrumComponent();
    ~DrumComponent();
    
    void resized() override;

private:
    std::vector<DrumPadComponent*> padsDrum;
};

#endif  // DRUMCOMPONENT_H_INCLUDED
