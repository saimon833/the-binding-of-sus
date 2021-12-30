#pragma once
#include "resources.h"
class MyContactListener : public b2ContactListener {
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
};
