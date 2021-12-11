#pragma once
#include "layer.h"
class GameObject{
    public:
        CommonResources* m_commonResources;
        GameObject(){};
        virtual ~GameObject(){};
        virtual void update()=0;
        virtual void render()=0;
};