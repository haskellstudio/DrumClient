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

class HeaderListener;

class HeaderComponent : public Component,
                        public Button::Listener
{
    
public:
    HeaderComponent();
    ~HeaderComponent();
    
    HeaderListener* listener = nullptr;
    
    void addHeaderListener(HeaderListener* _listener);
    void buttonClicked(Button* button) override;
    void resized() override;
    void paint(juce::Graphics &g) override;
    
    enum HeaderButtons {
        DRUM,
        MIXER,
        SETTINGS
    };

private:
    ImageButton drumButton;
    ImageButton mixerButton;
    ImageButton settingsButton;
    ImageComponent logo;
};

class HeaderListener
{
public:
    virtual ~HeaderListener()  {}
    virtual void headerChanged(HeaderComponent::HeaderButtons headerButton) = 0;
};

#endif  // HEADERCOMPONENT_H_INCLUDED
