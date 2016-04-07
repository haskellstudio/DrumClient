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

using namespace std;

class NotificationCentre
{
public:
    NotificationCentre();
    ~NotificationCentre();
    static NotificationCentre* getInstance();
    
    class ObserverDrumPad
    {
    public:
        virtual ~ObserverDrumPad() {};
        virtual void drumPadWasReleasedIn(Point<int> position, int sampleId) = 0;
    };

    void addObserverOfDrumPad(ObserverDrumPad* observer, const String& notificationKey);
    void removeObserverOfDrumPad(ObserverDrumPad* observer, const String& notificationKey);
    void sendNotification(const String& notificationKey, String& message) {};
    void sendNotificationForDrumPad(const String& notificationKey, Point<int> position, int sampleId);
    
    
private:
    map<String, vector<ObserverDrumPad*>> observersDrumPad;
};



#endif  // NOTIFICATIONCENTRE_H_INCLUDED
