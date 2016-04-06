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

class MixerComponent;

class TablePadType : public TableListBox,
                     public TableListBoxModel,
                     public DrumPadComponent::Listener,
                     public Button::Listener

{
public:
    TablePadType(MixerComponent* _mixer, float _width);
    ~TablePadType();
    int getNumRows() override;
    void paintRowBackground(Graphics&, int rowNumber, int width, int height, bool rowIsSelected) override {};
    void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override {};
    Component* refreshComponentForRow (int rowNumber, bool isRowSelected, Component* existingComponentToUpdate) override;
    void drumPadWasClicked(DrumPadComponent* sender) override;
    void drumPadWasTouchedDown(DrumPadComponent* sender) override;
    void buttonClicked(Button*) override;
    
private:
    MixerComponent* mixer;
    bool isShowingCategories = true;
    PadType typeShowing = PadType::None;
    vector<sampleInfoS> subCategory;
    ImageButton* tableHeaderButton;
};


#endif  // TABLEPADTYPE_H_INCLUDED
