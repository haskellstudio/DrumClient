/*
  ==============================================================================

    SampleInfo.cpp
    Created: 5 Apr 2016 3:29:21pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "SampleInfo.h"

using namespace std;

static SampleInfo* sharedInstance;

SampleInfo::~SampleInfo(){}
SampleInfo::SampleInfo()
{
    for (int i = 0; i < 20; ++i) {
        sampleInfoS info;
        int sampleId = i + 1;
        info.name = SampleInfo::getFakeNameForSample(sampleId);
        info.image = getImageBySampleId(sampleId);
        samples.insert(make_pair(i, info));
    }
}

SampleInfo* SampleInfo::getInstance()
{
    if (! sharedInstance) {
        sharedInstance = new SampleInfo();
    }
    return sharedInstance;
}

sampleInfoS SampleInfo::getInfoForSampleId(int sampleId)
{
    for (auto pair : samples)
        if (pair.first == sampleId)
            return pair.second;
    
    return sampleInfoS();
}

String SampleInfo::getNameForSampleId(int sampleId)
{
    return getInfoForSampleId(sampleId).name;
}

String SampleInfo::getFakeNameForSample(int sampleId)
{
    String name;
    if (sampleId < 6) {
        name = "Snare";
    } else if (sampleId < 11) {
        name = "Kick";
    } else if (sampleId < 16) {
        name = "Tom";
    } else if (sampleId < 21) {
        name = "Hi Hat";
    }
    return name + String(sampleId % 5);
}

Image SampleInfo::getImageBySampleId(int sampleId)
{
    switch (sampleId % 10) {
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

