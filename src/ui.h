#pragma once
#include <string>

#include "game_object.h"
//! Klasa interfejsu
class UI : public GameObject {
private:
    //! Wskaźnik na strukturę SDL_Renderer
    SDL_Renderer *m_renderer;
    //! Wskaźnik na teksturę TTF_Font
    TTF_Font *m_font;
    int textw = 0, texth = 0;
    //! Kolor czcionki
    SDL_Color m_color = {0, 0, 0};
    //! Wskaźnik na element potrzebny do stworzenia napisu
    SDL_Surface *m_surface = nullptr;
    //! Wskaźnik na texturę
    SDL_Texture *m_texture = nullptr;
    //! Obiekt std::string przechowujący aktualne informacje dla UI
    std::string m_displayText;
    SDL_Rect m_dstRec;

public:
    //! Konstruktor
    /**
     * @param ren wskaźnik na SDL_Renderer
     * @param commonResources adres do struktury CommonResources
     * @param x pozycja na osi x
     * @param y pozycja na osi y
     */
    UI(SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    //! Destruktor
    virtual ~UI() override;
    //! Funkcja służąca do przekazania do renderera parametrów tekstury
    virtual void render() override;
    //! Funkcja służąca do aktualizowania stanu obiektu
    virtual void update() override;
    //! Funckja służąca do resetowania stanu obiektu
    virtual void reset() {};
    //! Funkcja służąca do wywołania następnego etapu gry
    virtual void nextStage() {};
};