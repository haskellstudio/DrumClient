/*
  ==============================================================================

    TablePadType.h
    Created: 5 Apr 2016 4:48:51pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef TABLEPADTYPE_H_INCLUDED
#define TABLEPADTYPE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MixerComponent;

class TablePadType : public TableListBox,
                     public TableListBoxModel

{
public:
    TablePadType(MixerComponent* _mixer, float _width);
    ~TablePadType();
    int getNumRows() override;
    void paintRowBackground(Graphics&, int rowNumber, int width, int height, bool rowIsSelected) override {};
    void paintCell(Graphics&, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override {};
    Component* refreshComponentForRow (int rowNumber, bool isRowSelected, Component* existingComponentToUpdate) override;

private:
    MixerComponent* mixer;
    float width;
};


#endif  // TABLEPADTYPE_H_INCLUDED
