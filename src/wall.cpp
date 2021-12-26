#include "wall.h"
Wall::Wall(b2World *world, int x, int y, int h, int w) {
    // m_renderer = ren;
    m_xpos = x;
    m_ypos = y;
    m_height = h;
    m_width = w;
    //    m_srcRec.h = m_height;
    //    m_srcRec.w = m_width;
    //    m_srcRec.x = 0;
    //    m_srcRec.y = 0;
    //    m_dstRec.x = m_xpos;
    //    m_dstRec.y = m_ypos;
    //    m_dstRec.w = m_srcRec.w * 2;
    //    m_dstRec.h = m_srcRec.h * 2;

    //    auto m_hitBox = new b2BodyDef();
    //    m_hitBox->type = b2_staticBody;
    //    m_hitBox->position.Set(x, y);
    //    m_hitBox->angle = 0;
    //    m_hitBox->linearDamping = 1.0f;
    //    m_hitBox->angularDamping = 1.0f;
    //    m_body = world->CreateBody(m_hitBox);
    //    auto shape=new b2PolygonShape();
    //    shape->SetAsBox(h,w);
    //    b2FixtureDef fixtureDef;
    //    fixtureDef.shape = shape;
    //   fixtureDef.density = 1.0f;
    //    fixtureDef.friction = 1;
    //    m_body->CreateFixture(&fixtureDef);
    b2BodyDef myBodyDef;
    myBodyDef.type=b2_staticBody;
    myBodyDef.position.Set(x,y);
    myBodyDef.angle=0;
    m_body=world->CreateBody(&myBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(w,h);
    b2FixtureDef fixture;
    fixture.shape=&boxShape;
    fixture.density=1;
    m_body->CreateFixture(&fixture);
}
void Wall::update() {
}
void Wall::render() {
    // SDL_RenderCopy(m_renderer, /*m_objTexture,*/ &m_srcRec, &m_dstRec);
}
Wall::~Wall() {
}