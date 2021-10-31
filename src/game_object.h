#pragma once
#ifndef game_object_h
#define game_object_h
#include "game.h"
class GameObject{
    private:
        int xpos;
        int ypos;
        SDL_Texture* obj_texture;
        SDL_Rect src_rec, dst_rec;
        SDL_Renderer* renderer;
    public:
        GameObject(const char* texture_sheet, SDL_Renderer* ren, int x, int y);
        ~GameObject();
        void update();
        void render();
};


#endif