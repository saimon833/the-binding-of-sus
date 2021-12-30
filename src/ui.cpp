#include "ui.h"
#include <iostream>
UI::UI(SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
    m_position.x = x;
    m_position.y = y;
    m_renderer = ren;
    m_commonResources = &commonResources;
    m_dstRec.x = m_position.x;
    m_dstRec.y = m_position.y;
    m_dstRec.h = 50;
    m_dstRec.w = 300;
    m_font = TTF_OpenFont("/usr/share/fonts/TTF/OpenSans-Regular.ttf", 25);
}
UI::~UI() {
    TTF_CloseFont(m_font);
    if (m_surface) SDL_FreeSurface(m_surface);
    if (m_texture) SDL_DestroyTexture(m_texture);
}
void UI::update() {
    if (m_surface) SDL_FreeSurface(m_surface);
    if (m_texture) SDL_DestroyTexture(m_texture);
    if (!m_font) std::cout << "Font Loading Error" << std::endl;
    m_displayText = "Player HP: " + std::to_string(*(m_commonResources->playerHP)) + " " + "Boss HP: " + std::to_string(*(m_commonResources->bossHP));
    m_surface = TTF_RenderText_Solid(m_font, m_displayText.c_str(), m_color);
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &textw, &texth);
}
void UI::render() {
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstRec);
}