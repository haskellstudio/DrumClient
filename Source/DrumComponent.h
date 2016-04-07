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
                      public NotificationCentre::ObserverDrumPad
{
public:
    DrumComponent(MixerComponent* _mixer);
    ~DrumComponent();
    

    /// Component Overrides
    void resized() override;
//    bool hitTest (int x, int y) override;
    void paint (Graphics& g) override;

    
    int addPad(int sampleId); /// return padId
    DrumPadComponent* getPadByPadId(int padId);
    void changeSampleToPadId(int sampleId, int padId);
    void playSound(int padId);
    
    ////   NotificationCentre::ObserverDrumPad      overrides
    void drumPadWasReleasedIn(Point<int> position, int sampleId) override;


private:
    std::vector<DrumPadComponent*> padsDrum;
    MixerComponent* mixer;
};

#endif  // DRUMCOMPONENT_H_INCLUDED
