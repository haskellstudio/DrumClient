/*
  ==============================================================================

    SampleInfo.cpp
    Created: 5 Apr 2016 3:29:21pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "SampleInfo.h"

#define     kSampleNumber       (30)

using namespace std;

static SampleInfo* sharedInstance;

SampleInfo::~SampleInfo(){}
SampleInfo::SampleInfo()
{
    for (int i = 0; i < kSampleNumber; ++i) {
        sampleInfoS info;
        int sampleId = i + 1;
        info.sampleId = sampleId;
        info.type = getFakeTypeForSample(sampleId);
        info.name = getFakeNameForSample(sampleId);
        info.image = getImageByCategory(info.type);
        samples.insert(make_pair(sampleId, info));
    }
    for (int i = 0; i < kNumberOfPadTypes; ++i) {
        sampleInfoS info;
        int sampleId = i + 1;
        info.sampleId = 0;
        info.type = PadType(i + 1);
        info.name = getNameForCategory(info.type);
        info.image = getImageByCategory(info.type);
        categories.insert(make_pair(sampleId, info));
    }
}

SampleInfo* SampleInfo::getInstance()
{
    if (! sharedInstance)
        sharedInstance = new SampleInfo();

    return sharedInstance;
}

sampleInfoS SampleInfo::getInfoForCategory(PadType categoryType)
{
    for (auto pair : categories)
        if (pair.second.type == categoryType)
            return pair.second;
    
    return sampleInfoS();
}

PadType SampleInfo::getCategoryOfSample(int sampleId)
{
    return getInfoForSampleId(sampleId).type;
}

vector<sampleInfoS> SampleInfo::getAllSamplesWithCategory(PadType typeCategory)
{
    vector<sampleInfoS> selection;

    for (auto pair : samples)
        if (pair.second.type == typeCategory)
            selection.push_back(pair.second);
    
    return selection;
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
    return getNameForCategory(getFakeTypeForSample(sampleId)) + "\n" + String(sampleId);
}

PadType SampleInfo::getFakeTypeForSample(int sampleId)
{
    if (sampleId < kSampleNumber*0.35f) {
        return Snare;
    } else if (sampleId < kSampleNumber*0.7f) {
        return Tom;
    } else {
        return HiHat;
    }
}

Image SampleInfo::getImageBySampleId(int sampleId)
{
    return getImageByCategory(getInfoForSampleId(sampleId).type);
}

Image SampleInfo::getImageByCategory(PadType type)
{
    switch (type) {
        case HiHat:
            return ImageCache::getFromMemory (BinaryData::drumHiHat_png, BinaryData::drumHiHat_pngSize);
        case Snare:
            return ImageCache::getFromMemory (BinaryData::drumSnare_png, BinaryData::drumSnare_pngSize);
        case Tom:
            return ImageCache::getFromMemory (BinaryData::drumTom_png, BinaryData::drumTom_pngSize);
        default:
            return ImageCache::getFromMemory (BinaryData::drumSnare_png, BinaryData::drumSnare_pngSize);
    }
}

String SampleInfo::getNameForCategory(PadType type)
{
    switch (type) {
        case Snare:
            return "Snare";
        case Tom:
            return "Tom";
        case HiHat:
            return "HiHat";
        default:
            return "";
    }
}


