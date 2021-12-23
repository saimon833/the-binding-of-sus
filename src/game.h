#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <box2d/box2d.h>
#include "game_object.h"
#include "layer.h"
class Game{
    private:
        bool m_isRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        std::vector<GameObject*> m_objects;
        CommonResources m_commonResources;
        b2World* m_b2world;
        const double m_timeStep = 1./300.;
        double m_physicsTimeAccumulator=0.0;
        const double m_physicsDelay = 1./60.;
    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handle_events();
        void update(float frameTime);
        void render();
        void clean();
        bool running(){ return m_isRunning; }
        
};