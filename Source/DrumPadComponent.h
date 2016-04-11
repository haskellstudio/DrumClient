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
#include "SampleInfo.h"

class MixerComponent;

class DrumPadComponent : public Component,
                         public Button::Listener
{
public:

    /// Constructors
    DrumPadComponent(int _padId, int _sampleId, MixerComponent* _mixer, bool _isDraggable);
    DrumPadComponent(sampleInfoS infoSample, bool _isDraggable);
    ~DrumPadComponent();
    
    void init(int _padId, int _sampleId, MixerComponent* _mixer, bool _isDraggable);
    void init(sampleInfoS infoSample, bool _isDraggable);
    
    
    /// Component Overrides
    void resized() override;
    bool hitTest (int x, int y) override;
    
    /// Button::Listener Overrides
    void buttonClicked(Button* button) override;
    void buttonStateChanged (Button*) override;
    
    //// MouseListener Overrides
//    void mouseDrag (const MouseEvent& event) override;

    //// Accessors
    inline bool isBeingDragged() {return isDragging;};
    inline bool isBelongingToDrum() {return padId;};
    inline bool isCategoryItem() {return ! sampleId;}
    inline int getPadId() {return padId;};
    inline int getSampleId() {return sampleId;};
    inline String getSampleName() {return sampleLabel->getText();};
    inline PadType getCategoryType() {return typeCategory;};
    void setSample(int _sampleId);

    
    void startDragging();
    void stopDragging();

    class Listener
    {
    public:
        virtual ~Listener() {};
        virtual void drumPadWasClicked(DrumPadComponent* sender) = 0;
        virtual void drumPadWasTouchedDown(DrumPadComponent* sender) = 0;
    };
    
    void addListener(DrumPadComponent::Listener* _listener) {listener = _listener;};

private:
    bool isDraggable;
    int padId = 0;
    int sampleId = 0;
    bool isDragging = false;
    Point<int> firstHitTestPoint;
    DrumPadComponent::Listener* listener = nullptr;
    ImageButton padButton;
    MixerComponent* mixer;
    Label* sampleLabel;
    PadType typeCategory;
    
    void addComponentsAndInit();;

};



#endif  // DRUMPADCOMPONENT_H_INCLUDED
