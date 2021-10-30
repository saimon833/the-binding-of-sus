#ifndef texturemanager_h
#define texturemanager_h
#include "game.h"
class TextureManager{
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};

#endif