#pragma once
#include "game.h"
#include "game_object.h"
//! Klasa ściany ograniczającej mapę
class Wall : public GameObject {
private:
    //! pozycja na osi x
    int m_height;
    //! pozycja na osi y
    int m_width;
    //! wskaźnik do ciała fizycznego
    b2Body *m_body;
    /* data */
public:
    //! Konstruktor
    /**
     * @param world wskaźnik do obiektu świata gry
     * @param x pozycja na osi x
     * @param y pozycja na osi y
     * @param h wysokość ściany
     * @param w szerokość ściany
     */
    Wall(b2World *world, const int &x, const int &y, const int &h, const int &w);
    //! Destruktor
    ~Wall();
    //! Funkcja służąca do przekazania do renderera parametrów tekstury
    virtual void render(){};
    //! Funkcja służąca do aktualizowania stanu obiektu
    virtual void update(){};
    //! Funckja służąca do resetowania stanu obiektu
    virtual void reset(){};
    //! Funkcja służąca do wywołania następnego etapu gry
    virtual void nextStage(){};
};
