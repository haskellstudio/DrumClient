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

void NotificationCentre::addObserverOfDrumPad(ObserverDrumPad *observer, const String& notificationKey)
{
    observersDrumPad[notificationKey].push_back(observer);
}

void NotificationCentre::removeObserverOfDrumPad(ObserverDrumPad *observer, const String& notificationKey)
{
    auto pairWithKey = observersDrumPad.find(notificationKey);
    if (pairWithKey != observersDrumPad.end()) {
        auto observersWithKey = pairWithKey->second;
        auto observerIterator = find(observersWithKey.begin(), observersWithKey.end(), observer);
        if (observersWithKey.end() != observerIterator) {
            observersWithKey.erase(observerIterator);
        }
    }
}

void NotificationCentre::sendNotificationForDrumPad(const String& notificationKey, Point<int> position, int sampleId)
{
    auto pairWithKey = observersDrumPad.find(notificationKey);
    if (pairWithKey != observersDrumPad.end()) {
        for (auto observerOfDrumPads : pairWithKey->second) {
            observerOfDrumPads->drumPadWasReleasedIn(position, sampleId);
        }
    }
}
