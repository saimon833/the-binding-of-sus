#pragma once
#include "game_object.h"
#include "texture_manager.h"
class Actor : public GameObject {
   protected:
    SDL_Texture *m_objTexture;
    SDL_Rect m_srcRec, m_dstRec;
    SDL_Renderer *m_renderer;
    b2Body *m_body;
    position m_startPosition;
    /* data */
    virtual void updatePosition();
    void resetBodyPosition();

   public:
    Actor(){};
    virtual ~Actor(){};
    virtual void render() override;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual void nextStage() = 0;
};
