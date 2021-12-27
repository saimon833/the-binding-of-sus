#include "boss.h"
#include <cstdlib>
#define VELOCITY 3
Boss::Boss(b2World *world, const char *texture_sheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture(texture_sheet, m_renderer);
    GameObject::m_commonResources = &commonResources;
    m_xpos = x - m_commonResources->gameProperties.spiriteSize;
    m_ypos = y - m_commonResources->gameProperties.spiriteSize;
    m_srcRec.h = m_commonResources->gameProperties.spiriteSize;
    m_srcRec.w = m_commonResources->gameProperties.spiriteSize;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
    // b2PolygonShape hitBox;
    // hitBox.SetAsBox(2, 1);

    auto m_hitBox = new b2BodyDef();
    m_hitBox->type = b2_dynamicBody;
    m_hitBox->position.Set(x, y);
    m_hitBox->angle = 0;
    m_hitBox->linearDamping = 1.0f;
    m_hitBox->angularDamping = 1.0f;
    m_body = world->CreateBody(m_hitBox);
    b2CircleShape shape;
    shape.m_radius = m_srcRec.w;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1;
    m_body->CreateFixture(&fixtureDef);
}
void Boss::update() {
    move();
    updatePosition();
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
    // std::cout << m_xpos << " " << m_ypos << std::endl;
}
void Boss::move() {
    m_moveTimeAccumulator += m_commonResources->timeStep;
    if (m_moveTimeAccumulator > 1500 || (m_body->GetLinearVelocity().x == 0 && m_body->GetLinearVelocity().y == 0)) {
        m_newVelocity.x = 0;
        m_newVelocity.y = 0;
        
        int direction;
        do{
            direction=rand()%4;
        }
        while(direction%2 == m_lastDirection%2);
        switch (direction) {
            case 0: {
                m_newVelocity.x = VELOCITY;
                break;
            }
            case 2: {
                m_newVelocity.x = -VELOCITY;
                break;
            }
            case 1: {
                m_newVelocity.y = VELOCITY;
                break;
            }
            case 3: {
                m_newVelocity.y = -VELOCITY;
                break;
            }
        }
        m_lastDirection=direction;
        m_moveTimeAccumulator = 0;
    } 
    
    m_body->SetLinearVelocity(m_newVelocity);
}
