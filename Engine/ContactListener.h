#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Base/Base.h>

class Entity;

class ContactListener {
public:
    ContactListener();

    virtual void contactBegins(Entity *a, Entity *b) = 0;
    virtual void contactEnds(Entity *a, Entity *b) = 0;

private:
};

#endif