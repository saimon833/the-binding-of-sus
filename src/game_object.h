#pragma once
#include "resources.h"
class GameObject {
protected:
    position m_position;
    static int m_nextID;
    const int m_ID;
    bool m_markedForDelete = 0;

public:
    CommonResources *m_commonResources;
    GameObject();
    virtual ~GameObject(){};
    virtual void update() = 0;
    virtual void render() = 0;
    position getPos() const { return m_position; };
    hitInfo m_hitInfo;
    int getID() { return m_ID; };
    bool getMarkForDelete() { return m_markedForDelete; };
};