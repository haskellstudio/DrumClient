/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "HeaderComponent.h"
#include "DrumComponent.h"
#include "MixerComponent.h"
#include "FakeAudioEngine.h"
#include "TablePadType.h"
#include "SampleInfo.h"
#include "MetronomeComponent.h"

//==============================================================================
MainContentComponent::~MainContentComponent(){}
MainContentComponent::MainContentComponent()
{
    SampleInfo::getInstance();
    audioEngine = new FakeAudioEngine();
    Rectangle<int> screenSize = Desktop::getInstance().getDisplays().getMainDisplay().userArea;

    header = new HeaderComponent();
    header->addHeaderListener(this);
    mixer = new MixerComponent(audioEngine);
    drum = new DrumComponent(mixer);
    metronome = new MetronomeComponent();
    tableTypes = new TablePadType(mixer, screenSize.getWidth()*0.125f, true);

    addAndMakeVisible(header, 2);
    addAndMakeVisible(drum, 0);
    addAndMakeVisible(metronome, 0);
    addAndMakeVisible(mixer, 0);
    addAndMakeVisible(tableTypes, 10);
    mixer->setAlpha(0.0f);
    metronome->setAlpha(0.0f);
    
    focusViews.push_back(drum);
    focusViews.push_back(mixer);
    focusViews.push_back(metronome);
    
    setSize (screenSize.getWidth(), screenSize.getHeight());
    
    showSideTable(true);
}

void MainContentComponent::paint(Graphics& g)
{
    g.fillAll(Colours::grey);
}

void MainContentComponent::resized()
{
    float width = getWidth();
    float height = getHeight();
    float tableTypesWidth = width*0.125f;
    Rectangle<int> focusArea(tableTypesWidth, height*0.14f, width - tableTypesWidth, height*0.86f + 2.0f);
    header->setBounds(0, 0, width, height*0.14f);
    drum->setBounds(focusArea);
    mixer->setBounds(Rectangle<int>(0, focusArea.getY(), width, focusArea.getHeight()));
    metronome->setBounds(mixer->getBounds());
    tableTypes->setBounds(-1.1f*tableTypesWidth, focusArea.getY(), tableTypesWidth, focusArea.getHeight());
}

void MainContentComponent::headerChanged(HeaderComponent::HeaderButtons headerButton)
{
    showFocusView(headerButton);
    
    if (HeaderComponent::HeaderButtons::MIXER == headerButton || HeaderComponent::HeaderButtons::METRONOME == headerButton)
        hideSideTable();
    else
        showSideTable(HeaderComponent::HeaderButtons::DRUM == headerButton);
}

void MainContentComponent::showFocusView(HeaderComponent::HeaderButtons viewButtonPressed)
{
    float animationDuration = 350;
    for (auto view : focusViews)
        if (view->getAlpha() > 0)
            Desktop::getInstance().getAnimator().fadeOut(view, animationDuration*0.3f);
    
    switch (viewButtonPressed) {
        case HeaderComponent::HeaderButtons::MIXER:
            mixer->setAlwaysOnTop(true);
            Desktop::getInstance().getAnimator().cancelAnimation(mixer, true);
            Desktop::getInstance().getAnimator().fadeIn(mixer, animationDuration);
            break;
        case HeaderComponent::HeaderButtons::METRONOME:
            metronome->setAlwaysOnTop(true);
            Desktop::getInstance().getAnimator().cancelAnimation(metronome, true);
            Desktop::getInstance().getAnimator().fadeIn(metronome, animationDuration);
            break;
        default:
            drum->setAlwaysOnTop(true);
            Desktop::getInstance().getAnimator().cancelAnimation(drum, true);
            Desktop::getInstance().getAnimator().fadeIn(drum, animationDuration);
            break;
    }
    
}

void MainContentComponent::showSideTable(bool isDrumKit)
{
    if (!isShowingSideTable) {
        isShowingSideTable = true;
        
        Desktop::getInstance().getAnimator().cancelAnimation(tableTypes, true);
        Desktop::getInstance().getAnimator().animateComponent(tableTypes,
                                                              Rectangle<int>(0.0f, tableTypes->getY(), tableTypes->getWidth(), tableTypes->getHeight()),
                                                              1.0f, 300, false, 1.0f, 0.2f);
    }
    tableTypes->setIsShowingDrumKits(isDrumKit);
}

void MainContentComponent::hideSideTable()
{
    if (isShowingSideTable) {
        isShowingSideTable = false;
        Desktop::getInstance().getAnimator().cancelAnimation(tableTypes, true);
        Desktop::getInstance().getAnimator().animateComponent(tableTypes,
                                        Rectangle<int>(-1.1f*tableTypes->getWidth(), tableTypes->getY(), tableTypes->getWidth(), tableTypes->getHeight()),
                                                              1.0f, 300, false, 1.0f, 0.2f);
    }
}






