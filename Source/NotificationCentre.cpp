/*
  ==============================================================================

    NotificationCentre.cpp
    Created: 7 Apr 2016 1:32:58pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#include "NotificationCentre.h"

static NotificationCentre* sharedInstance;

NotificationCentre::NotificationCentre() {}
NotificationCentre::~NotificationCentre() {}

NotificationCentre* NotificationCentre::getInstance()
{
    if (! sharedInstance)
        sharedInstance = new NotificationCentre();
    
    return sharedInstance;
}

void NotificationCentre::addObserver(Observer *observer, const String& notificationKey)
{
    observers[notificationKey].push_back(observer);
}

void NotificationCentre::removeObserver(Observer *observer, const String& notificationKey)
{
    auto pairWithKey = observers.find(notificationKey);
    if (pairWithKey != observers.end()) {
        auto observersWithKey = pairWithKey->second;
        auto observerIterator = find(observersWithKey.begin(), observersWithKey.end(), observer);
        if (observersWithKey.end() != observerIterator) {
            observersWithKey.erase(observerIterator);
        }
    }
}

void NotificationCentre::sendNotificationForDrumPad(const String& notificationKey, Point<int> position, int sampleId)
{
    auto pairWithKey = observers.find(notificationKey);
    if (pairWithKey != observers.end())
        for (auto observerOfDrumPads : pairWithKey->second)
            ((ObserverDrumPad*)observerOfDrumPads)->drumPadWasReleasedIn(position, sampleId);
    
}
void NotificationCentre::sendNotificationForDrumKit(const String& notificationKey, String drumKitName)
{
    auto pairWithKey = observers.find(notificationKey);
    if (pairWithKey != observers.end())
        for (auto observerOfDrumKit : pairWithKey->second)
            ((ObserverDrumKit*)observerOfDrumKit)->setDrumKit(drumKitName);

}

