#pragma once
#include "actor.h"
/**
 * Klasa służąca do tworzenia obektu przeciwnika
 */
class Boss : public Actor {
   private:
    //! Wartość typu int opisująca numer etapu gry
    int m_bossStage = 0;
    //! Wartość typu float przechowująca prędkość liniową obiektu
    float m_velocity;
    //! Funkcja służąca do przemieszczenia obiektu w świecie gry
    void move();
    // Uint32 m_moveTimeAccumulator = 1501;
    //! Struktura b2Vec2 przechowująca składowe prędkości obiektu
    b2Vec2 m_newVelocity;
    //! Wartość typu int przechująca punkty życia przeciwnika
    int m_hp;
    //! Wartość typu double służąca do poprawnego odczytywania trafień pociskami
    double m_hitTimeAccumulator = 0.0;
    //! Funckja obliczająca 1/sqrt(x)
    /**
     * Funkcja zaczerpnięta z kodu źródłowego Queake'a 3
     * Funkcja ta aproksymuje wartość wyrażenia z wystarczającą dokładnością
     * @param number Liczba, z której ma być obliczona wartość 1/sqrt(x)
     * @return Zwraca obliczone wyrażenie  
     */
    float Q_rsqrt(float number);

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
    Boss(b2World *world, const char *textureSheet, SDL_Renderer *ren, CommonResources &commonResources, const int &x, const int &y);
    //! Destruktor
    /** Dekonstuuje obiekt */
    virtual ~Boss() override;
    //! Funkcja służąca do aktualizowania stanu obiektu
    virtual void update() override;
    //! Funckja służąca do resetowania stanu obiektu
    virtual void reset() override;
    //! Funkcja służąca do wywołania następnego etapu gry
    virtual void nextStage() override;
};