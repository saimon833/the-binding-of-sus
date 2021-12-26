#pragma once
#include "game_object.h"
#include "texture_manager.h"
class Actor : public GameObject {
private:
    int m_xpos;
    int m_ypos;
    SDL_Texture *m_objTexture;
    SDL_Rect m_srcRec, m_dstRec;
    SDL_Renderer *m_renderer;
    b2Body *m_body;
    /* data */
    void updatePosition();
    void updatePhysics();
    void spawnProjectile();
    std::vector<GameObject> m_objects;

public:
    Actor(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, int x, int y);
    ~Actor();
    virtual void render() override;
    virtual void update() override;
    int getPosX(){return m_xpos;}
    int getPosY(){return m_ypos;}
};
