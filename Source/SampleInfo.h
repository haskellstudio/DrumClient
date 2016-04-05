/*
  ==============================================================================

    SampleInfo.h
    Created: 5 Apr 2016 3:29:21pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef SAMPLEINFO_H_INCLUDED
#define SAMPLEINFO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <map>

using namespace std;

struct sampleInfoS {
    String name = "";
    Image image;
};

class SampleInfo
{
public:
    SampleInfo();
    ~SampleInfo();
    
    String getNameForSampleId(int sampleId);
    sampleInfoS getInfoForSampleId(int sampleId);
    static SampleInfo* getInstance();
    Image getImageBySampleId(int sampleId);
    int getNumberOfSamples() {return (int)samples.size();};

private:
    map<int, sampleInfoS> samples;
    String getFakeNameForSample(int sampleId);
};


#endif  // SAMPLEINFO_H_INCLUDED
