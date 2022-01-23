#pragma once
#include "game.h"
//! Klasa służąca do tworzenia struktury zawierającą teksturę
class TextureManager {
public:
    //! Funkcja statyczna tworząca teksturę
    /**
     * @param filename nazwa pliku z teksturą
     * @param ren wskaźnik na strukturę SDL_Renderer
     * @return zwraca wskaźnik na strukturę SDL_Texture
     */
    static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *ren);
};
