#pragma once
#include "game_object.h"
#include "resources.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
//! Klasa główna gry
class Game {
private:
    //! Wartość przechowująca informację, czy gra jest uruchomiona
    bool m_isRunning;
    //! Wskaźnik do struktury przechowującą informacje o oknie aplikacji
    SDL_Window *m_window;
    //! Wskaźnik do struktury przechowującej informacje o rendererze 
    SDL_Renderer *m_renderer;
    //! Obiekt klasy vector przechowujący wskaźniki do wszystkich obiektów gry
    std::vector<GameObject *> m_objects;
    //! Struktura przechowująca dane potrzebne w różnych miejscach programu
    CommonResources m_commonResources;
    //! Wskaźnik do obiektu świata silnika fizycznego
    b2World *m_b2world;
    //! Wartość określająca 
    const double m_timeStep = 1. / 300.;
    //! Wartość służąca do wykonywania obliczeń fizycznych
    double m_physicsTimeAccumulator = 0.0;
    //! Wartość służąca do ograniczenia szybkostrzelności gracza
    double m_shootingTimeAccumulator = 0.0;
    //! Wartość określająca co ile wykonywać obliczenia fizyczne
    const double m_physicsDelay = 1. / 60.;
    //! Wartość ograniczająca szybkostrzelność
    const double m_shootingDelay = 250.;
    //! Funkcja służąca do tworzenia pocisków w grze
    void spawnProjectile(float frameTime);

public:
    //! Konstruktor
    Game();
    //! Destruktor
    ~Game();
    //! Funckja inicjalizująca grę
    /**
     * @param title łancuch znakowy przechowujący informacje o tytule okienka
     * @param xpos pozycja na ekranie na osi x
     * @param ypos pozycja na ekranie na osi y
     * @param width szerokość okna
     * @param height wysokość okna
     * @param fullscreen czy aplikacja ma być pełnoekranowa;
     */
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    //! Funkcja odpowiedzialna za odczytywanie stanów klawiszy
    void handleEvents();
    //! Funkcja aktualizująca obiekty gry
    /**
     * @param frameTime czas trwania poprzedniej klatki
     */
    void update(float frameTime);
    //! Funkcja renderująca obiekty gry
    void render();
    //! Funkcja czyszcząca grę
    void clean();
    //! Funkcja zwracająca informację, czy gra jest uruchomiona
    /**
     * @return Informacja o tym, czy gra jest utuchomiona
     */
    bool running() { return m_isRunning; }
    //! Funkcja zatrzymująca grę
    void stop() {m_isRunning=0;}
};