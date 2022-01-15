#pragma once
#include "actor.h"
class Player : public Actor {
protected:
    void moveOnInput();
    double m_damageTimeAccumulator = 0.0;
    bool m_recentlyDamaged = 0;
    int m_HP = 4;

public:
    Player(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    virtual ~Player() override;
    virtual void update() override;
    virtual void reset() override;
    virtual void nextStage() override;
};
