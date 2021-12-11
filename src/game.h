#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include "game_object.h"
#include "layer.h"
class Game{
    private:
        bool m_isRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        std::vector<GameObject> m_objects;
        CommonResources m_commonResources; 

    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handle_events();
        void update();
        void render();
        void clean();
        bool running(){ return m_isRunning; }
        
};