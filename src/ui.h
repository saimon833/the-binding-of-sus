#pragma once
#include "game_object.h"
#include <string>
class UI : public GameObject {
private:
    SDL_Renderer *m_renderer;
    TTF_Font *m_font;
    int textw = 0, texth = 0;
    SDL_Color m_color = {0, 0, 0};
    SDL_Surface *m_surface = nullptr;
    SDL_Texture *m_texture = nullptr;
    std::string m_displayText;
    SDL_Rect m_dstRec;

public:
    UI(SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    virtual ~UI() override;
    virtual void update() override;
    virtual void render() override;
};