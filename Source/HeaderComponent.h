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
    void paint(juce::Graphics &g) override;
    
    enum HeaderButtons {
        DRUM,
        MIXER,
        SETTINGS,
        METRONOME
    };
    
    class HeaderListener
    {
    public:
        virtual ~HeaderListener()  {}
        virtual void headerChanged(HeaderComponent::HeaderButtons headerButton) = 0;
    };
    
    inline void addHeaderListener(HeaderListener* _listener) {listener = _listener;};
    inline HeaderButtons getCurrentTab() {return currentTab;};

private:
    ImageButton drumButton;
    ImageButton mixerButton;
    ImageButton settingsButton;
    ImageButton metronomeButton;
    ImageComponent logo;
    HeaderButtons currentTab = HeaderButtons::DRUM;
    HeaderListener* listener = nullptr;
};


#endif  // HEADERCOMPONENT_H_INCLUDED
