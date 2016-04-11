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

class AudioEngineGuiInterface;
class DrumComponent;
class MixerComponent;
class TablePadType;

class MainContentComponent   : public Component,
                               public HeaderListener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
    
    ////        Component               overrides
    void resized() override;
    void paint (Graphics& g) override;

    ////        HeaderListener          overrides
    void headerChanged(HeaderComponent::HeaderButtons headerButton) override;
    

private:
    HeaderComponent* header;
    DrumComponent* drum;
    MixerComponent* mixer;
    TablePadType* tableTypes;
    AudioEngineGuiInterface* audioEngine;
    std::vector<Component*> focusViews;
    
    bool isShowingSideTable = false;
    void showSideTable(bool isDrumKit);
    void hideSideTable();
    void showFocusView(HeaderComponent::HeaderButtons viewButtonPressed);
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};




#endif  // MAINCOMPONENT_H_INCLUDED
