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
#include "NotificationCentre.h"

class DrumPadComponent;
class MixerComponent;

class DrumComponent : public Component,
                      public NotificationCentre::ObserverDrumKit
{
public:
    DrumComponent(MixerComponent* _mixer);
    ~DrumComponent();
    
    int addPad(int sampleId); /// return padId
    DrumPadComponent* getPadByPadId(int padId);
    void changeSampleToPadId(int sampleId, int padId);
    void playSound(int padId);

    /// Component Overrides
    void resized() override;
    void paint (Graphics& g) override;
    
    ////   NotificationCentre::ObserverDrumPad      overrides
    void drumPadWasReleasedIn(Point<int> position, int sampleId) override;

    ////   NotificationCentre::ObserverDrumKit      overrides
    void setDrumKit(String& drumKitName) override;

private:
    std::vector<DrumPadComponent*> padsDrum;
    MixerComponent* mixer;
};

#endif  // DRUMCOMPONENT_H_INCLUDED
