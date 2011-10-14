#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Base/Base.h>

class Entity;

class ContactListener {
public:
    ContactListener();

    virtual void contactBegins(ContactListener *a, ContactListener *b);
    virtual void contactEnds(ContactListener *a, ContactListener *b);

private:
};

typedef std::list<ContactListener*> ContactListenerList;

#endif