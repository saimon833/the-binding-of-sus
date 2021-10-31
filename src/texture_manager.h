#pragma once
#ifndef texture_manager_h
#define texture_manager_h
#include "game.h"
class TextureManager{
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};

#endif