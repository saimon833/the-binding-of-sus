#include "obstacle.h"
#include <cstdlib>
#include <ctime>
Obstacle::Obstacle(b2World *world, SDL_Renderer *ren, CommonResources &commonResources) {
    GameObject::m_commonResources = &commonResources;
    int size = m_commonResources->gameProperties.spiriteSize;
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture("assets/box.png", m_renderer);
    m_xpos = random(m_commonResources->gameProperties.window_w) - m_commonResources->gameProperties.spiriteSize;
    m_ypos = random(m_commonResources->gameProperties.window_h) - m_commonResources->gameProperties.spiriteSize;
    //std::cout << m_xpos << " " << m_ypos << std::endl;
    m_srcRec.h = m_commonResources->gameProperties.spiriteSize;
    m_srcRec.w = m_commonResources->gameProperties.spiriteSize;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.w = m_srcRec.w * m_commonResources->gameProperties.scale;
    m_dstRec.h = m_srcRec.h * m_commonResources->gameProperties.scale;
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(m_xpos + 32, m_ypos + 32);
    myBodyDef.angle = 0;
    m_body = world->CreateBody(&myBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(size, size);
    b2FixtureDef fixture;
    fixture.shape = &boxShape;
    fixture.density = 1;
    m_body->CreateFixture(&fixture);
}
int Obstacle::random(int n) {
    int tmp = rand() % (n - 128) + 50;
    return tmp-tmp%70;
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
Obstacle::~Obstacle() {}