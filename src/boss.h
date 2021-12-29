#pragma once
#include "actor.h"
class Boss : public Actor {
private:
    void move();
    Uint32 m_moveTimeAccumulator = 1501;
    b2Vec2 m_newVelocity;
    int m_lastDirection = 5;
    int m_hp;
    double m_hitTimeAccumulator = 0.0;
    float Q_rsqrt(float number);

public:
    Boss(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    virtual ~Boss() override;
    virtual void update() override;
};