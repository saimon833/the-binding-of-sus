#include "player.h"
#define VELOCITY 5
Player::Player(b2World *world, const char *texture_sheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y) {
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture(texture_sheet, m_renderer);
    GameObject::m_commonResources = &commonResources;
    m_posiotion.x = x - m_commonResources->gameProperties.spiriteSize;
    m_posiotion.y = y - m_commonResources->gameProperties.spiriteSize;
    m_srcRec.h = m_commonResources->gameProperties.spiriteSize;
    m_srcRec.w = m_commonResources->gameProperties.spiriteSize;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_posiotion.x;
    m_dstRec.y = m_posiotion.y;
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
    //m_body->GetUserData().pointer=m_ID;
    //m_body->GetUserData().pointer=(uintptr_t)this;
    //m_body->GetUserData().pointer=m_contact;
    //m_contact=0;
    //m_body->GetUserData().pointer=(uintptr_t)&m_contact;
    m_hitInfo.self_id=m_ID;
    m_body->GetUserData().pointer=(uintptr_t)&m_hitInfo;

}
void Player::update() {
    moveOnInput();
    updatePosition();
    m_dstRec.x = m_posiotion.x;
    m_dstRec.y = m_posiotion.y;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
    // std::cout << m_xpos << " " << m_ypos << std::endl;
}

void Player::moveOnInput() {
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
Player::~Player() {
    SDL_DestroyTexture(m_objTexture);
}