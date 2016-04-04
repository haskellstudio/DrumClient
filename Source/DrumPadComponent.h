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

class DrumPadComponent : public Component,
                         public Button::Listener
{
public:

    DrumPadComponent(int _padId);
    ~DrumPadComponent();
    
    static inline Image getImageByDrumPadId(int padId);
    void resized() override;
    void buttonClicked(Button* button) override;

private:
    int padId;
    ImageButton padButton;

    
};



#endif  // DRUMPADCOMPONENT_H_INCLUDED
