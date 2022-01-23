#pragma once
#include "game.h"
#include "game_object.h"
#include "texture_manager.h"
//! Klasa opisująca przeszkody na mapie
class Obstacle : public GameObject {
private:
    //! Wartość opisująca wysokość textury
    int m_height;
    //! Wartość opisująca szerokość textury
    int m_width;
    //! Skalowanie textury
    int scale;
    //! Obiekty służące do renderowania tekstury
    SDL_Texture *m_objTexture;
    //! Wskaźnik do renderera SLD_Renderer
    SDL_Rect m_srcRec, m_dstRec;
    //! Wskaźnik do ciała fizycznego z silnika Box2D
    b2Body *m_body;
    //! Wskaźnik do renderera SLD_Renderer
    SDL_Renderer *m_renderer;
    // SDL_Renderer *m_renderer;
    //! Funkcja losująca wartość losową
    /**
     * @param n wartość maksymalna
     * @return wylosowana liczba
     */
    int random(int n);
    //! Funckja ustawiająca pozycję obiektu w silniku fizycznym
    /**
     * @param newPosition struktura typu b2Vec2 przechowująca informacje o nowej pozycji
     */
    void resetBodyPosition(b2Vec2 newPosition);

public:
    //! Konstruktor
    /**
     * Konstruuje obiekt
     * @param world wskaźnik na obiekt typu b2world
     * @param ren wskaźnik na strukturę typu SDL_Renderer
     * @param commonResources referencja do struktury CommonResources
     */
    Obstacle(b2World *world, SDL_Renderer *ren, CommonResources &commonResources);
    //! Destruktor
    ~Obstacle();
    //! Funkcja renderująca obiekt na ekranie
    virtual void render() override;
    //! Funkcja służąca do aktualizowania stanu obiektu
    virtual void update() override;
    //! Funckja służąca do resetowania stanu obiektu
    virtual void reset() override;
    //! Funkcja służąca do wywołania następnego etapu gry
    virtual void nextStage() override;
};