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
    Wall(b2World *world, const int &x, const int &y, const int &h, const int &w);
    ~Wall();
    virtual void render() override{};
    virtual void update() override{};
    virtual int getPosX() const override { return m_xpos; }
    virtual int getPosY() const override { return m_ypos; }
};
