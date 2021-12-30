#pragma once
#include <cstdint>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <box2d/box2d.h>
struct KeyState {
    bool moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
    bool shootUp = 0, shootDown = 0, shootLeft = 0, shootRight = 0;
};
struct GameProperties {
    int window_h;
    int window_w;
    void *gameptr;
};
struct position {
    int x, y;
};
struct hitInfo {
    bool m_contact = 0;
    int self_id;
    int hit_id;
    bool hitRegistered = 0;
};

struct CommonResources {
    KeyState keyState;
    GameProperties gameProperties;
    position *playerPosition;
    double timeStep;
    int *playerHP, *bossHP;
};
