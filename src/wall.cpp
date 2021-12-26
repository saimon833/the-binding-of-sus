#include "wall.h"
Wall::Wall(b2World *world, int x, int y, int h, int w) {
    // m_renderer = ren;
    m_xpos = x;
    m_ypos = y;
    m_height = h;
    m_width = w;
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
Wall::~Wall() {
}