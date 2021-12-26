#pragma once
#include "game_object.h"
#include "resources.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <box2d/box2d.h>
#include <cstdint>
#include <iostream>
#include <vector>

class Game {
private:
    bool m_isRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    std::vector<GameObject *> m_objects;
    CommonResources m_commonResources;
    b2World *m_b2world;
    const double m_timeStep = 1. / 300.;
    double m_physicsTimeAccumulator = 0.0;
    double m_shootingTimeAccumulator = 0.0;
    const double m_physicsDelay = 1. / 60.;
    const double m_shootingDelay = 250.;
    void spawnProjectile(float frameTime);

public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, bool fullscreen);
    void handleEvents();
    void update(float frameTime);
    void render();
    void clean();
    bool running() { return m_isRunning; }
};