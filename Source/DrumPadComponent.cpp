/*
  ==============================================================================

    DrumPadComponent.cpp
    Created: 4 Apr 2016 2:00:50pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "DrumPadComponent.h"


DrumPadComponent::~DrumPadComponent(){}
DrumPadComponent::DrumPadComponent(int _padId)
{
    padId = _padId;
    Image image = getImageByDrumPadId(_padId);
    padButton.setImages(false, true, true, image, 1.0f, Colours::transparentBlack, image, 1.0f, Colours::white, image, 1.0f, Colours::white);
    padButton.addListener(this);
    padButton.setEnabled(true);
    addAndMakeVisible(padButton);

}

void DrumPadComponent::buttonClicked(juce::Button *button)
{
    Logger::writeToLog("Yeah");
}


void DrumPadComponent::resized()
{
    padButton.centreWithSize(getWidth(), getHeight());
}
Image DrumPadComponent::getImageByDrumPadId(int padId)
{
    switch (padId) {
        case 1:
            return ImageCache::getFromMemory (BinaryData::padImage1_png, BinaryData::padImage1_pngSize);
        case 2:
            return ImageCache::getFromMemory (BinaryData::padImage2_png, BinaryData::padImage2_pngSize);
        case 3:
            return ImageCache::getFromMemory (BinaryData::padImage3_png, BinaryData::padImage3_pngSize);
        case 4:
            return ImageCache::getFromMemory (BinaryData::padImage4_png, BinaryData::padImage4_pngSize);
        case 5:
            return ImageCache::getFromMemory (BinaryData::padImage5_png, BinaryData::padImage5_pngSize);
        case 6:
            return ImageCache::getFromMemory (BinaryData::padImage6_png, BinaryData::padImage6_pngSize);
        case 7:
            return ImageCache::getFromMemory (BinaryData::padImage7_png, BinaryData::padImage7_pngSize);
        case 8:
            return ImageCache::getFromMemory (BinaryData::padImage8_png, BinaryData::padImage8_pngSize);
        case 9:
            return ImageCache::getFromMemory (BinaryData::padImage9_png, BinaryData::padImage9_pngSize);
        default:
            return ImageCache::getFromMemory (BinaryData::padImage10_png, BinaryData::padImage10_pngSize);
    }
}
