#include "projectile.h"
#define VELOCITY 10
Projectile::Projectile(b2World *world, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture("assets/projectile.png", m_renderer);
    GameObject::m_commonResources = &commonResources;
    if (m_commonResources->keyState.shootUp) {
        m_ypos = y + 32 - 64;
        m_xpos = x + 32;
        m_velocity.x = 0;
        m_velocity.y = -VELOCITY;
    } else if (m_commonResources->keyState.shootDown) {
        m_ypos = y + 32 + 64;
        m_xpos = x + 32;
        m_velocity.x = 0;
        m_velocity.y = VELOCITY;
    } else if (m_commonResources->keyState.shootLeft) {
        m_ypos = y + 32;
        m_xpos = x + 32 - 64;
        m_velocity.x = -VELOCITY;
        m_velocity.y = 0;
    } else if (m_commonResources->keyState.shootRight) {
        m_ypos = y + 32;
        m_xpos = x + 32 + 64;
        m_velocity.x = VELOCITY;
        m_velocity.y = 0;
    }
    m_srcRec.h = 12;
    m_srcRec.w = 12;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.h = m_srcRec.h * 2;
    m_dstRec.w = m_srcRec.w * 2;
    auto m_hitBox = new b2BodyDef();
    m_hitBox->type = b2_dynamicBody;
    m_hitBox->position.Set(m_xpos - 12, m_ypos - 12);
    m_hitBox->angle = 0;
    m_hitBox->linearDamping = 0.;
    m_hitBox->angularDamping = 0.;
    m_body = world->CreateBody(m_hitBox);
    b2CircleShape shape;
    shape.m_radius = m_srcRec.w;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetLinearVelocity(m_velocity);
}
void Projectile::updatePosition() {
    auto position = m_body->GetPosition();
    m_xpos = position.x;
    m_ypos = position.y;
    //std::cout<<m_xpos<<" "<<m_ypos<<std::endl;
}
void Projectile::update() {
    updatePosition();
    m_dstRec.x = m_xpos - 12;
    m_dstRec.y = m_ypos - 12;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
}
Projectile::~Projectile() {}
void Projectile::render() {
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}