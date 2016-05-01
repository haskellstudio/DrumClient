/*
  ==============================================================================

    SampleInfo.cpp
    Created: 5 Apr 2016 3:29:21pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "SampleInfo.h"

#define     kSampleNumber       (40)

using namespace std;

static SampleInfo* sharedInstance;

SampleInfo* SampleInfo::getInstance()
{
    if (! sharedInstance)
        sharedInstance = new SampleInfo();
    
    return sharedInstance;
}

SampleInfo::~SampleInfo()
{}

SampleInfo::SampleInfo()
{
    initFakeSamples();
    initFakeCategories();
    initFakeDrumKits();
}

void SampleInfo::initFakeDrumKits()
{
    int numOfFakeDrumKit = 10;
    for (int i = 0; i < numOfFakeDrumKit; ++i) {
        vector<int> drumKit;
        for (int j = 0; j < kMaxNumberOfPads; ++j) {
            int newSample = ((11*j) % kSampleNumber) + 1;
            while (find(drumKit.begin(), drumKit.end(), newSample) != drumKit.end()) {
                newSample = (((11*j)) % kSampleNumber) + 1;
            }
            drumKit.push_back(newSample);
        }
        drumKits.insert(make_pair(getFakeNameForDrumKit(i), drumKit));
    }
}

void SampleInfo::initFakeSamples()
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
}

void SampleInfo::initFakeCategories()
{
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

vector<int>& SampleInfo::getDrumKitByName(String drumKitName)
{
    auto pair = drumKits.find(drumKitName);
    if (pair != drumKits.end()) {
        return pair->second;
    } else {
        return *new vector<int>();
    }
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

vector<sampleInfoS>& SampleInfo::getAllSamplesWithCategory(PadType typeCategory)
{
    vector<sampleInfoS> *selection = new vector<sampleInfoS>();

    for (auto pair : samples)
        if (pair.second.type == typeCategory)
            selection->push_back(pair.second);
    
    return *selection;
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
    if (sampleId < kSampleNumber*0.26f) {
        return Snare;
    } else if (sampleId < kSampleNumber*0.51f) {
        return Tom;
    } else if (sampleId < kSampleNumber*0.76) {
        return HiHat;
    } else {
        return Kick;
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
        case Kick:
            return ImageCache::getFromMemory (BinaryData::drumKick_png, BinaryData::drumKick_pngSize);
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
        case Kick:
            return "Kick";
        default:
            return "";
    }
}

String SampleInfo::getFakeNameForDrumKit(int drumKitId)
{
    switch (drumKitId) {
        case 1:
            return "Yamaha 2";
        case 2:
            return "Tama 1";
        case 3:
            return "Tama 2";
        case 4:
            return "Ludwig 1";
        case 5:
            return "Ludwig 2";
        case 6:
            return "Pearl 1";
        case 7:
            return "Pearl 2";
        case 8:
            return "Roland";
        case 9:
            return "Sonor";
        default:
            return "Yamaha 1";
    }
}

Image SampleInfo::getImageForDrumKit(String drumKitName)
{
    return ImageCache::getFromMemory (BinaryData::headerDrum_png, BinaryData::headerDrum_pngSize);
}


