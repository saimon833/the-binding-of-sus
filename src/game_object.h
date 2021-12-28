#pragma once
#include "resources.h"
class GameObject {
protected:
    position m_posiotion;
    static int m_nextID;
    const int m_ID;

public:
    CommonResources *m_commonResources;
    GameObject();
    virtual ~GameObject(){};
    virtual void update() = 0;
    virtual void render() = 0;
    position getPos() const { return m_posiotion; };
};