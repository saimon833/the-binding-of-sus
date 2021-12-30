#include "obstacle.h"
#include <cstdlib>
#include <ctime>
Obstacle::Obstacle(b2World *world, SDL_Renderer *ren, CommonResources &commonResources) {
    GameObject::m_commonResources = &commonResources;
    int size = 32;
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture("assets/box.png", m_renderer);
    m_position.x = random(800) - 32;
    m_position.y= random(600) - 32;
    //std::cout << m_xpos << " " << m_ypos << std::endl;
    m_srcRec.h = 32;
    m_srcRec.w = 32;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_position.x;
    m_dstRec.y = m_position.y;
    m_dstRec.w = m_srcRec.w * 2;
    m_dstRec.h = m_srcRec.h * 2;
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(m_position.x+ 32, m_position.y + 32);
    myBodyDef.angle = 0;
    m_body = world->CreateBody(&myBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(size, size);
    b2FixtureDef fixture;
    fixture.shape = &boxShape;
    fixture.density = 1;
    m_body->CreateFixture(&fixture);
    //m_body->GetUserData().pointer=m_ID;
    //m_body->GetUserData().pointer=(uintptr_t)this;
    //m_body->GetUserData().pointer=m_contact;
    //m_contact=0;
    //m_body->GetUserData().pointer=(uintptr_t)&m_contact;
    m_hitInfo.self_id=m_ID;
    m_body->GetUserData().pointer=(uintptr_t)&m_hitInfo;

}
int Obstacle::random(int n) {
    int tmp = rand() % (n - 200) + 150;
    return tmp - tmp % 70;
}
void Obstacle::update() {
    //m_dstRec.x = m_xpos;
    //m_dstRec.y = m_ypos;
    //m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    //m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
}
void Obstacle::render() {
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}
Obstacle::~Obstacle() {
    SDL_DestroyTexture(m_objTexture);
}