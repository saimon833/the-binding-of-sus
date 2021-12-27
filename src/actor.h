#pragma once
#include "game_object.h"
#include "texture_manager.h"
class Actor : public GameObject {
protected:
    int m_xpos;
    int m_ypos;
    SDL_Texture *m_objTexture;
    SDL_Rect m_srcRec, m_dstRec;
    SDL_Renderer *m_renderer;
    b2Body *m_body;
    /* data */
    virtual void updatePosition();

public:
    Actor(){};
    virtual ~Actor(){};
    virtual void render() override;
    virtual void update() = 0;
    virtual int getPosX() const override { return m_xpos; };
    virtual int getPosY() const override { return m_ypos; };
};
