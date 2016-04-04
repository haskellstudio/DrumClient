/*
  ==============================================================================

    HeaderComponent.h
    Created: 3 Apr 2016 3:53:59pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef HEADERCOMPONENT_H_INCLUDED
#define HEADERCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class HeaderComponent : public Component,
                        public Button::Listener
{
    
public:
    HeaderComponent();
    ~HeaderComponent();
    

    
    void buttonClicked(Button* button) override;
    void resized() override;

private:
    ImageButton drumButton;
    ImageButton mixerButton;
    ImageButton settingsButton;
    ImageComponent logo;

};

#endif  // HEADERCOMPONENT_H_INCLUDED
