#pragma once
#include "actor.h"
class Player : public Actor {
protected:
    void moveOnInput();

public:
    Player(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    virtual ~Player() override;
    virtual void update() override;
};
