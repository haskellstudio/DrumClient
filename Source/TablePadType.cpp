/*
  ==============================================================================

    TablePadType.cpp
    Created: 5 Apr 2016 4:48:51pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "TablePadType.h"
#include "MixerComponent.h"

TablePadType::~TablePadType(){}
TablePadType::TablePadType(MixerComponent* _mixer, float _width)
{
    mixer = _mixer;
    setModel(this);
    setRowHeight(_width*0.8f);
    setHeaderHeight(_width*0.8f);
    
    tableHeaderButton = new ImageButton();
    tableHeaderButton->addListener(this);
    tableHeaderButton->setEnabled(false);
    auto image = ImageCache::getFromMemory (BinaryData::headerDrum_png, BinaryData::headerDrum_pngSize);
    tableHeaderButton->setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    tableHeaderButton->setBounds(_width*0.1f, _width*0.1f, _width*0.8f, _width*0.6f);
    getHeader().addAndMakeVisible(tableHeaderButton);
    
    NotificationCentre::getInstance()->addObserverOfDrumPad(this, kDrumWasReleased);
}

void TablePadType::drumPadWasClicked(DrumPadComponent* sender)
{
    if (isShowingCategories) {
        isShowingCategories = false;
        typeShowing = sender->getCategoryType();
        subCategory = SampleInfo::getInstance()->getAllSamplesWithCategory(typeShowing);
        tableHeaderButton->setEnabled(true);
        auto image = SampleInfo::getInstance()->getImageByCategory(typeShowing);
        tableHeaderButton->setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
        updateContent();
    }
}



void TablePadType::buttonClicked(Button* button)
{
    if (button == tableHeaderButton && ! isShowingCategories) {
        isShowingCategories = true;
        tableHeaderButton->setEnabled(false);
        auto image = ImageCache::getFromMemory (BinaryData::headerDrum_png, BinaryData::headerDrum_pngSize);
        tableHeaderButton->setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
        updateContent();
    }
}

void TablePadType::drumPadWasTouchedDown(DrumPadComponent* sender)
{}

void TablePadType::drumPadWasReleasedIn(Point<int> position, int sampleId)
{
    updateContent();
}

int TablePadType::getNumRows()
{
    if (isShowingCategories)    return kNumberOfPadTypes;
    else                        return (int)subCategory.size();
}

Component* TablePadType::refreshComponentForRow(int rowNumber, bool isRowSelected, juce::Component *existingComponentToUpdate)
{
    DrumPadComponent* cell;
    if (existingComponentToUpdate) {
        if (((DrumPadComponent*)existingComponentToUpdate)->isBeingDragged()) {
            existingComponentToUpdate->getParentComponent()->removeChildComponent(existingComponentToUpdate);
            delete existingComponentToUpdate;
            cell = new DrumPadComponent(0, subCategory[rowNumber].sampleId, mixer, true);
            cell->addListener(this);
        } else {
            cell = (DrumPadComponent*)existingComponentToUpdate;
            if (isShowingCategories) {
                cell->init(SampleInfo::getInstance()->getInfoForCategory(PadType(rowNumber + 1)), false);
            } else {
                cell->init(0, subCategory[rowNumber].sampleId, mixer, true);
            }
            
        }
    } else {
        if (isShowingCategories) {
            cell = new DrumPadComponent(SampleInfo::getInstance()->getInfoForCategory(PadType(rowNumber + 1)), false);
        } else {
            cell = new DrumPadComponent(0, subCategory[rowNumber].sampleId, mixer, true);
        }
        cell->addListener(this);
    }
    return cell;
}

