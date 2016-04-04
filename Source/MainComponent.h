/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "HeaderComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class DrumComponent;
class MixerComponent;

class MainContentComponent   : public Component,
                               public HeaderListener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    
    void resized() override;
    void headerChanged(HeaderComponent::HeaderButtons headerButton) override;


private:
    HeaderComponent* header;
    DrumComponent* drum;
    MixerComponent* mixer;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
