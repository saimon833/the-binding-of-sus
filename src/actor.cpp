#include "actor.h"
#define VELOCITY 5
Actor::Actor(b2World *world, const char *texture_sheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
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
void Actor::update() {
    updatePhysics();
    updatePosition();
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
    //std::cout << m_xpos << " " << m_ypos << std::endl;
}
void Actor::render() {
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}
Actor::~Actor() {
}
void Actor::updatePhysics() {
    b2Vec2 newVelocity;
    newVelocity.x = 0;
    newVelocity.y = 0;
    if (m_commonResources->keyState.moveUp) {
        // m_ypos-=1;
        newVelocity.y = -VELOCITY;
    } else if (m_commonResources->keyState.moveDown) {
        // m_ypos+=1;
        newVelocity.y = VELOCITY;
    }
    if (m_commonResources->keyState.moveLeft) {
        newVelocity.x = -VELOCITY;
    } else if (m_commonResources->keyState.moveRight) {
        newVelocity.x = VELOCITY;
    }
    if (newVelocity.x != 0 && newVelocity.y != 0) {
        newVelocity *= 0.7;
    }
    m_body->SetLinearVelocity(newVelocity);
    // std::cout<<newVelocity.x<<"\t"<<newVelocity.y<<std::endl;
}
void Actor::updatePosition() {
    auto position = m_body->GetPosition();
    m_xpos = position.x - 32;
    m_ypos = position.y - 32;
    //std::cout<<m_xpos<<" "<<m_ypos<<std::endl;
}
