#pragma once
#include "game.h"
#include "game_object.h"
class Wall : public GameObject {
private:
    int m_xpos;
    int m_ypos;
    int m_height;
    int m_width;
    SDL_Texture *m_objTexture;
    SDL_Rect m_srcRec, m_dstRec;
    //SDL_Renderer *m_renderer;
    b2Body *m_body;
    /* data */
public:
    Wall(b2World *world, int x, int y, int h, int w);
    ~Wall();
    virtual void render() override;
    virtual void update() override;
};
