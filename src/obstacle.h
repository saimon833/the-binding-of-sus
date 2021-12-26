#pragma once
#include "game.h"
#include "game_object.h"
#include "texture_manager.h"
class Obstacle : public GameObject {
private:
    int m_xpos;
    int m_ypos;
    int m_height;
    int m_width;
    int scale;
    SDL_Texture *m_objTexture;
    SDL_Rect m_srcRec, m_dstRec;
    b2Body *m_body;
    SDL_Renderer *m_renderer;
    // SDL_Renderer *m_renderer;
    int random(int n);

public:
    Obstacle(b2World *world, SDL_Renderer *ren, CommonResources &commonResources);
    ~Obstacle();
    virtual void render() override;
    virtual void update() override;
    virtual int getPosX() const override { return m_xpos; }
    virtual int getPosY() const override { return m_ypos; }
};