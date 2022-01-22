#pragma once
#include "actor.h"
//! Klasa gracza
class Player : public Actor {
protected:
    //! Funkcja przemieszczająca gracza
    /**
     * Funckja ta zmienia położenie gracza na podstawie wciśniętych klawiszy
     */
    void moveOnInput();
    //! Wartość ograniczająca otrzymywanie obrażeń
    /** Ogranicza otrzymywanie obrażeń od przeciwnika do 1 punkt życia na jedną sekundę */
    double m_damageTimeAccumulator = 0.0;
    //! Wartość opisująca, czy obiekt otzymał obrażenia
    bool m_recentlyDamaged = 0;
    //! Wartość określająca liczbe punktów życia
    int m_HP = 4;

public:
    //! Konstruktor
    /**
     * Konstruuje obiekt
     * @param world wskaźnik na obiekt typu b2world
     * @param textureSheet wskaźnik na strukturę SDL_Texture przechowujący texture obiektu
     * @param ren wskaźnik na strukturę typu SDL_Renderer
     * @param commonResources referencja do struktury CommonResources
     * @param x pozycja x w układzie współrzędnych
     * @param y pozycja y w układzie współrzędnych
     */
    Player(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    //! Destruktor
    /** Dekonstuuje obiekt */
    virtual ~Player() override;
    //! Funkcja aktualizująca stan gracza
    virtual void update() override;
    //! Funckja resetująca stan gracza
    virtual void reset() override;
    //! Funkcja ustawiająca następną fazę gry
    virtual void nextStage() override;
};
