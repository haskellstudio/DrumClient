/*
  ==============================================================================

    AudioEngineGuiInterface.h
    Created: 5 Apr 2016 11:45:04am
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef AUDIOENGINEGUIINTERFACE_H_INCLUDED
#define AUDIOENGINEGUIINTERFACE_H_INCLUDED

class AudioEngineGuiInterface
{
public:
    virtual ~AudioEngineGuiInterface()  {}
    virtual void playSamples(int sampleId, float volume) = 0;
};

#endif  // AUDIOENGINEGUIINTERFACE_H_INCLUDED
