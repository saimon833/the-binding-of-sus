#pragma once
#include "resources.h"
class GameObject {
public:
    CommonResources *m_commonResources;
    GameObject(){};
    virtual ~GameObject(){};
    virtual void update() = 0;
    virtual void render() = 0;
    virtual int getPosX() const = 0;
    virtual int getPosY() const = 0;
};