/*
  ==============================================================================

    NotificationCentre.h
    Created: 7 Apr 2016 1:32:58pm
    Author:  Francesco Simonazzi

  ==============================================================================
*/

#ifndef NOTIFICATIONCENTRE_H_INCLUDED
#define NOTIFICATIONCENTRE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <map>

#define         kDrumWasReleased        "drumReleased"
#define         kDrumKitHasChanged      "drumKitChanged"

using namespace std;

class NotificationCentre
{
public:
    NotificationCentre();
    ~NotificationCentre();
    static NotificationCentre* getInstance();
    
    class Observer
    {};
    
    class ObserverDrumPad : public Observer
    {
    public:
        virtual ~ObserverDrumPad() {};
        virtual void drumPadWasReleasedIn(Point<int> position, int sampleId) = 0;
    };
    class ObserverDrumKit : public ObserverDrumPad
    {
    public:
        virtual ~ObserverDrumKit() {};
        virtual void setDrumKit(String& drumKitName) = 0;
    };

    void addObserver(Observer* observer, const String& notificationKey);
    void removeObserver(Observer* observer, const String& notificationKey);
    void sendNotification(const String& notificationKey, String& message) {};
    void sendNotificationForDrumPad(const String& notificationKey, Point<int> position, int sampleId);
    void sendNotificationForDrumKit(const String& notificationKey, String drumKitName);
    
private:
    map<String, vector<Observer*>> observers;
};



#endif  // NOTIFICATIONCENTRE_H_INCLUDED
