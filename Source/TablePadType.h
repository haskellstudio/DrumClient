/*
  ==============================================================================

    TablePadType.h
    Created: 5 Apr 2016 4:48:51pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef TABLEPADTYPE_H_INCLUDED
#define TABLEPADTYPE_H_INCLUDED

#include "DrumPadComponent.h"
#include "SampleInfo.h"
#include "NotificationCentre.h"

class MixerComponent;

class TablePadType : public TableListBox,
                     public TableListBoxModel,
                     public DrumPadComponent::Listener,
                     public Button::Listener,
                     public NotificationCentre::ObserverDrumPad

{
public:
    TablePadType(MixerComponent* _mixer, float _width, bool _isShowingDrumKits);
    ~TablePadType();
    
    void setIsShowingDrumKits(bool _isShowingDrumKits);
    
    ////        TableListBoxModel               overrides
    int getNumRows() override;
    void paintRowBackground(Graphics&, int rowNumber, int width, int height, bool rowIsSelected) override {};
    void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override {};
    Component* refreshComponentForRow (int rowNumber, bool isRowSelected, Component* existingComponentToUpdate) override;
    
    ////        DrumPadComponent::Listener      overrides
    void drumPadWasClicked(DrumPadComponent* sender) override;
    void drumPadWasTouchedDown(DrumPadComponent* sender) override;

    ////        Button::Listener                overrides           (tableHeaderButton)
    void buttonClicked(Button*) override;

    ////   NotificationCentre::ObserverDrumPad      overrides
    void drumPadWasReleasedIn(Point<int> position, int sampleId) override;

private:
    MixerComponent* mixer;
    bool isShowingCategories = true;
    bool isShowingDrumKits;
    PadType typeShowing = PadType::None;
    vector<sampleInfoS> subCategory;
    ImageButton* tableHeaderButton;
    vector<String> drumKitNames;
};


#endif  // TABLEPADTYPE_H_INCLUDED
