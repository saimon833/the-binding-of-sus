#ifndef game_h
#define game_h
#include <SDL2/SDL.h>
#include <iostream>
class Game{
    private:
        bool is_running;
        SDL_Window *window;
        SDL_Renderer *renderer;
        int cnt=0;
    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handle_events();
        void update();
        void render();
        void clean();
        bool running(){ return is_running; }
        
};

#endif