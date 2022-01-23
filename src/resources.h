#pragma once
#include <cstdint>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <box2d/box2d.h>
//! Struktura przechowująca informację o wciśnieciu klawiszy

struct KeyState {
    //! Kierunek ruchu w górę
    bool moveUp = 0;
    //! Kierunek ruchu w dół
    bool moveDown = 0;
    //! Kierunek ruchu w lewo
    bool moveLeft = 0;
    //! Kierunek ruchu w prawo
    bool moveRight = 0;
    //! Kierunek strzału w górę
    bool shootUp = 0;
    //! Kierunek strzału w dół
    bool shootDown = 0;
    //! Kierunek strzału w lewo
    bool shootLeft = 0;
    //! Kierunek strzału w prawo
    bool shootRight = 0;
};
//! Struktura przechowywująca informacje o grze
struct GameProperties {
    //! Wysokość okna
    int window_h;
    //! Szerokość okna
    int window_w;
    //! Wskaźnik do gry
    void *gameptr;
};
//! Struktura przechowująca informacje o pozycji
struct position {
    int x, y;
};
//! Struktura przechowująca informacje o kolizji
struct hitInfo {
    //! Zmienna określająca, czy kontakt trwa
    bool m_contact = 0;
    //! Zmienna określająca id obiektu
    int self_id;
    //! Zmienna określająca id obiektu z którym następuje kolizja
    int hit_id;
    //! Zmienna określająca czy kolizja została zarejestrowana
    bool hitRegistered = 0;
};
//! Struktura przechowująca dane wymagane przez różne obiekty
struct CommonResources {
    //! Wciśnięte klawisze
    KeyState keyState;
    //! Właściwości gry
    GameProperties gameProperties;
    //! Wskaźnik na strukturę z pozycją gracza
    position *playerPosition;
    //! Czas trwania klatki
    double timeStep;
    //! Wskaźniki na punkty życia gracza oraz przeciwnika
    int *playerHP, *bossHP;
};