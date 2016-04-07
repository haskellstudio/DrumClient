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

#define         kNumberOfPadTypes             (4)
#define         kMaxNumberOfPads              (10)

using namespace std;

enum PadType
{
    None = 0,
    HiHat = 1,
    Tom = 2,
    Snare = 3,
    Kick = 4
};

struct sampleInfoS
{
    String name = "";
    Image image;
    PadType type = PadType::None;
    int sampleId;
    
    sampleInfoS (String _name, Image _image, PadType _type, int _sampleId)  : name(_name), image(_image), type(_type), sampleId(_sampleId)
    {}
    sampleInfoS() {};
};

class SampleInfo
{
public:
    SampleInfo();
    ~SampleInfo();
    static SampleInfo* getInstance();
    
    String getNameForSampleId(int sampleId);
    sampleInfoS getInfoForSampleId(int sampleId);
    sampleInfoS getInfoForCategory(PadType categoryType);
    Image getImageBySampleId(int sampleId);
    Image getImageByCategory(PadType type);
    Image getImageForDrumKit(String drumKitName);
    vector<int>& getDrumKitByName(String drumKitName);
    map<String, vector<int>>& getAllDrumKits() {return drumKits;};
    int getNumberOfSamples() {return (int)samples.size();};
    PadType getCategoryOfSample(int sampleId);
    vector<sampleInfoS>& getAllSamplesWithCategory(PadType typeCategory);

private:
    map<int, sampleInfoS> categories;
    map<int, sampleInfoS> samples;
    map<String, vector<int>> drumKits;
    String getNameForCategory(PadType type);
    
    //// Fake Data Creation
    void initFakeSamples();
    void initFakeCategories();
    void initFakeDrumKits();
    String getFakeNameForSample(int sampleId);
    PadType getFakeTypeForSample(int sampleId);
    String getFakeNameForDrumKit(int drumKitId);
};


#endif  // SAMPLEINFO_H_INCLUDED
