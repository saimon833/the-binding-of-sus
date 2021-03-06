#include "boss.h"

#include <cstdlib>
#define VELOCITY 3
Boss::Boss(b2World *world, const char *texture_sheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture(texture_sheet, m_renderer);
    GameObject::m_commonResources = &commonResources;
    m_startPosition.x = x;
    m_startPosition.y = y;
    m_position.x = x;
    m_position.y = y;
    m_srcRec.h = 32;
    m_srcRec.w = 32;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_position.x;
    m_dstRec.y = m_position.y;
    m_dstRec.w = m_srcRec.w * 2;
    m_dstRec.h = m_srcRec.h * 2;
    m_commonResources->bossHP = &m_hp;
    m_velocity = VELOCITY;
    // b2PolygonShape hitBox;
    // hitBox.SetAsBox(2, 1);

    auto m_hitBox = new b2BodyDef();
    m_hitBox->type = b2_dynamicBody;
    m_hitBox->position.Set(x + 32, y + 32);
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
    // m_body->GetUserData().pointer=m_ID;
    m_hitInfo.self_id = m_ID;
    m_body->GetUserData().pointer = (uintptr_t)&m_hitInfo;
    m_hp = 100;
    // std::cout << "Current HP: " << m_hp << std::endl;
    //  std::cout <<Q_rsqrt(2)<<std::endl;
}
void Boss::update() {
    move();
    updatePosition();
    m_dstRec.x = m_position.x;
    m_dstRec.y = m_position.y;
    m_dstRec.w = m_srcRec.w * 2;
    m_dstRec.h = m_srcRec.h * 2;
    // std::cout<<m_contact<<std::endl;
    //  std::cout << m_xpos << " " << m_ypos << std::endl;
    if (m_hitInfo.m_contact = 1 && m_hitInfo.hit_id > 16 && !m_hitInfo.hitRegistered) {
        m_hitTimeAccumulator += m_commonResources->timeStep;
        if (m_hitTimeAccumulator > 50) {
            // std::cout << "Boss hit" << std::endl;
            m_hp -= 2;
            // std::cout << "Current HP: " << m_hp << std::endl;
            m_hitInfo.hitRegistered = 1;
            m_hitTimeAccumulator = 0;
        }
    }
    if (m_hp <= 0) m_nextStage = 1;
}
void Boss::move() {
    m_newVelocity.x = 0;
    m_newVelocity.y = 0;
    int dy = m_position.y - m_commonResources->playerPosition->y;
    int dx = m_position.x - m_commonResources->playerPosition->x;
    //    float vy, vx;
    //    if (dx != 0) {
    //        vx = 1 + dy * dy / (dx * dx);
    //        if (dx > 0)
    //            m_newVelocity.x = -VELOCITY * Q_rsqrt(vx);
    //        else if (dx < 0)
    //            m_newVelocity.x = VELOCITY * Q_rsqrt(vx);
    //    }
    //    if (dy != 0) {
    //        vy = dx * dx / (dy * dy) + 1;
    //        if (dy > 0)
    //            m_newVelocity.y = -VELOCITY * Q_rsqrt(vy);
    //        else if (dy < 0)
    //            m_newVelocity.y = VELOCITY * Q_rsqrt(vy);
    //    }
    m_newVelocity.x = -m_velocity * dx * Q_rsqrt(dx * dx + dy * dy);
    m_newVelocity.y = -m_velocity * dy * Q_rsqrt(dx * dx + dy * dy);
    m_body->SetLinearVelocity(m_newVelocity);
}
Boss::~Boss() {
    auto *world = m_body->GetWorld();
    world->DestroyBody(m_body);
    SDL_DestroyTexture(m_objTexture);
}
float Boss::Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    x2 = number * 0.5F;
    y = number;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));
    return y;
}
void Boss::nextStage() {
    m_nextStage = 0;
    m_reset = 0;
    m_bossStage++;
    m_velocity += m_bossStage * 0.5;
    //m_position = m_startPosition;
    m_position.x=m_startPosition.x;
    m_position.y=m_startPosition.y;
    m_hp = 100 * (1 + 0.5 * m_bossStage);
    resetBodyPosition();
}
void Boss::reset() {
    m_reset = 0;
    m_nextStage = 0;
    m_bossStage = 0;
    m_velocity = VELOCITY;
    //m_position = m_startPosition;
    m_position.x=m_startPosition.x;
    m_position.y=m_startPosition.y;
    m_hp = 100;
    resetBodyPosition();
}