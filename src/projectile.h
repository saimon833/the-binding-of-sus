#pragma once
#include "game.h"
#include "game_object.h"
#include "texture_manager.h"
//! Klasa pocisku
class Projectile : public GameObject {
private:
    //! Wskaźnik do struktury SDL_Texture przechowywujący informacje o texturze pocisku
    SDL_Texture *m_objTexture;
    //! Obiekty służące do renderowania tekstury
    SDL_Rect m_srcRec, m_dstRec;
    //! Wskaźnik do renderera SLD_Renderer
    SDL_Renderer *m_renderer;
    //! Wskaźnik do ciała fizycznego z silnika Box2D
    b2Body *m_body;
    //! Struktura przechowywująca wartości składowych wektora prędkości
    b2Vec2 m_velocity;
    //! Funkcja aktualizująca stan obiektu w silniku fizycznym
    void updatePhysics();
    //! Funkcja aktualizująca pozycje na ekranie
    void updatePosition();
    //! Wartość określająca czas życia pocisku w świecie gry
    double m_lifeTimeAccumulator = 0.0;

public:
    //! Konstruktor
    /**
     * Konstruuje obiekt
     * @param world wskaźnik na obiekt typu b2world
     * @param ren wskaźnik na strukturę typu SDL_Renderer
     * @param commonResources referencja do struktury CommonResources
     * @param x pozycja x w układzie współrzędnych
     * @param y pozycja y w układzie współrzędnych
     */
    Projectile(b2World *world, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    //! Destruktor
    ~Projectile();
    //! Funkcja renderująca obiekt na ekranie
    virtual void render() override;
    //! Funckja aktualizująca pozycje obiektu
    virtual void update() override;
    //! Funkcja resetująca obiekt
    virtual void reset() override{};
    //! Funkcja ustawiająca koleny etap gry
    virtual void nextStage() override{};
};