/*
  ==============================================================================

    TablePadType.cpp
    Created: 5 Apr 2016 4:48:51pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "TablePadType.h"
#include "SampleInfo.h"
#include "DrumPadComponent.h"
#include "MixerComponent.h"

TablePadType::~TablePadType(){}
TablePadType::TablePadType(MixerComponent* _mixer, float _width)
{
    mixer = _mixer;
    setModel(this);
    setHeaderHeight(100.0f);
    setRowHeight(_width*0.8f);
}

int TablePadType::getNumRows()
{
    return SampleInfo::getInstance()->getNumberOfSamples();
}

Component* TablePadType::refreshComponentForRow(int rowNumber, bool isRowSelected, juce::Component *existingComponentToUpdate)
{
    delete existingComponentToUpdate;
    auto cell = new DrumPadComponent(0, rowNumber + 1, mixer);
    cell->setBounds(0, 0, getWidth(), getWidth());
    return cell;
}

