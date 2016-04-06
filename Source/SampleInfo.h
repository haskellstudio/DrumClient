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

#define         kNumberOfCategories             (3)

using namespace std;

enum PadType {
    None = 0,
    HiHat = 1,
    Tom = 2,
    Snare = 3
};

struct sampleInfoS {
    String name = "";
    Image image;
    PadType type = PadType::None;
    int sampleId;
};

class SampleInfo
{
public:
    SampleInfo();
    ~SampleInfo();
    
    String getNameForSampleId(int sampleId);
    sampleInfoS getInfoForSampleId(int sampleId);
    sampleInfoS getInfoForCategory(PadType categoryType);
    
    static SampleInfo* getInstance();
    Image getImageBySampleId(int sampleId);
    Image getImageByCategory(PadType type);
    int getNumberOfSamples() {return (int)samples.size();};
    PadType getCategoryOfSample(int sampleId);
    vector<sampleInfoS> getAllSamplesWithCategory(PadType typeCategory);

private:
    map<int, sampleInfoS> categories;
    map<int, sampleInfoS> samples;
    String getFakeNameForSample(int sampleId);
    PadType getFakeTypeForSample(int sampleId);
    String getNameForCategory(PadType type);
};


#endif  // SAMPLEINFO_H_INCLUDED
