#include "projectile.h"
#define VELOCITY 5
Projectile::Projectile(b2World *world, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture("assets/projectile.png", m_renderer);
    GameObject::m_commonResources = &commonResources;
    if (m_commonResources->keyState.shootUp) {
        m_posiotion.y = y + 32 - 54;
        m_posiotion.x = x + 40;
        m_velocity.x = 0;
        m_velocity.y = -VELOCITY;
    } else if (m_commonResources->keyState.shootDown) {
        m_posiotion.y = y + 32 + 54;
        m_posiotion.x = x + 40;
        m_velocity.x = 0;
        m_velocity.y = VELOCITY;
    } else if (m_commonResources->keyState.shootLeft) {
        m_posiotion.y = y + 40;
        m_posiotion.x = x + 32 - 54;
        m_velocity.x = -VELOCITY;
        m_velocity.y = 0;
    } else if (m_commonResources->keyState.shootRight) {
        m_posiotion.y = y + 40;
        m_posiotion.x = x + 32 + 54;
        m_velocity.x = VELOCITY;
        m_velocity.y = 0;
    }
    m_srcRec.h = 6;
    m_srcRec.w = 6;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_posiotion.x;
    m_dstRec.y = m_posiotion.y;
    m_dstRec.h = m_srcRec.h * 2;
    m_dstRec.w = m_srcRec.w * 2;
    auto m_hitBox = new b2BodyDef();
    m_hitBox->type = b2_dynamicBody;
    m_hitBox->position.Set(m_posiotion.x - 6, m_posiotion.y - 6);
    m_hitBox->angle = 0;
    m_hitBox->linearDamping = 0.;
    m_hitBox->angularDamping = 0.;
    m_body = world->CreateBody(m_hitBox);
    b2CircleShape shape;
    shape.m_radius = m_srcRec.w;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 10.0f;
    fixtureDef.friction = 1;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetLinearVelocity(m_velocity);
    // m_body->GetUserData().pointer=m_ID;
    // m_body->GetUserData().pointer=(uintptr_t)this;
    // m_body->GetUserData().pointer=m_contact;
    //m_contact = 0;
    //m_body->GetUserData().pointer = (uintptr_t)&m_contact;
    m_hitInfo.self_id=m_ID;
    m_body->GetUserData().pointer=(uintptr_t)&m_hitInfo;

    m_body->SetBullet(true);
}
void Projectile::updatePosition() {
    auto position = m_body->GetPosition();
    m_posiotion.x = position.x;
    m_posiotion.y = position.y;
    m_lifeTimeAccumulator += m_commonResources->timeStep;

    // std::cout<<m_xpos<<" "<<m_ypos<<std::endl;
}
void Projectile::update() {
    updatePosition();
    if (m_lifeTimeAccumulator > 300. || m_hitInfo.m_contact) {
        m_markedForDelete = 1;
    }
    m_dstRec.x = m_posiotion.x - 6;
    m_dstRec.y = m_posiotion.y - 6;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
}
Projectile::~Projectile() {
    auto *world = m_body->GetWorld();
    world->DestroyBody(m_body);
    SDL_DestroyTexture(m_objTexture);
}
void Projectile::render() {
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}