#pragma once
#include "game.h"
#include "game_object.h"
#include "texture_manager.h"
class Projectile : public GameObject {
private:
    int m_xpos;
    int m_ypos;
    SDL_Texture *m_objTexture;
    SDL_Rect m_srcRec, m_dstRec;
    SDL_Renderer *m_renderer;
    b2Body *m_body;
    b2Vec2 m_velocity;
    void updatePhysics();
    void updatePosition();

public:
    Projectile(b2World *world, SDL_Renderer *ren, CommonResources &commonResources, int x, int y);
    ~Projectile();
    virtual void render() override;
    virtual void update() override;
    virtual int getPosX() override { return m_xpos; }
    virtual int getPosY() override { return m_ypos; }
};