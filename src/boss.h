#pragma once
#include "actor.h"
class Boss:public Actor{
private:
    void move();
    Uint32 m_moveTimeAccumulator=1501;
    b2Vec2 m_newVelocity;
    int m_lastDirection=5;
public:
    Boss(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    virtual ~Boss() override;
    virtual void update() override;
};