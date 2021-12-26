#pragma once
#include "game.h"
#include "game_object.h"
class Wall : public GameObject {
private:
    int m_xpos;
    int m_ypos;
    int m_height;
    int m_width;
    b2Body *m_body;
    /* data */
public:
    Wall(b2World *world, int x, int y, int h, int w);
    ~Wall();
    virtual void render() override{};
    virtual void update() override{};
    virtual int getPosX() override{return m_xpos;}
    virtual int getPosY() override{return m_ypos;}
};
