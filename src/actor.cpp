#include "actor.h"
void Actor::render() {
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}
void Actor::updatePosition() {
    auto position = m_body->GetPosition();
    m_position.x = position.x - 32;
    m_position.y = position.y - 32;
    // std::cout<<m_xpos<<" "<<m_ypos<<std::endl;
}
void Actor::resetBodyPosition() {
    b2Vec2 tmpPos;
    tmpPos.x = m_startPosition.x + 32;
    tmpPos.y = m_startPosition.y + 32;
    m_body->SetTransform(tmpPos, m_body->GetAngle());
}