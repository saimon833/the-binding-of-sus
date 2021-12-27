#include "actor.h"
void Actor::render() {
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}
void Actor::updatePosition() {
    auto position = m_body->GetPosition();
    m_xpos = position.x - 32;
    m_ypos = position.y - 32;
    //std::cout<<m_xpos<<" "<<m_ypos<<std::endl;
}