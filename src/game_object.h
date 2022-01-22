#pragma once
#include "resources.h"
//! Klasa abstrakcyjna służąca do definiowania wszystkich obiektów w programie
class GameObject {
   protected:
    //! Struktura przechowywująca dane o położeniu obiektu
    position m_position;
    //! Wartość statyczna służąca do określenia id obiektu podczas jego tworzenia
    static int m_nextID;
    //! Wartość int służąca do identyfikacji obiektu podczas kolizji
    const int m_ID;
    //! Wartość informująca klasę gry o przeznaczeniu obiektu do usunięcia
    bool m_markedForDelete = 0;
    //! Wartość informująca klasę gry o załadowaniu kolejnego etapu
    bool m_nextStage = 0;
    //! Wartość informująca klasę gry o zresetowaniu programu
    bool m_reset = 0;

   public:
    //! Wskaźnik na strukturę CommonResources
    CommonResources *m_commonResources;
    //! Konstruktor
    GameObject();
    //! Destruktor
    virtual ~GameObject(){};
    //! Funckja wirtualna służąca do zaktualizowania stanu obiektu
    virtual void update() = 0;
    //! Funkcja wirtualna służąca do wyrenderowania obiektu
    virtual void render() = 0;
    //! Funckja wirtualna służąca do zresetowania stanu obiektu
    virtual void reset() = 0;
    //! Funckja wirtualna służąca do ustawienia następnego etapu gry
    virtual void nextStage() = 0;
    //! Funkcja zwracająca pozycję obiektu
    /**
     * @return Zwraca strukturę zawierającą pozycje x i y obiektu
     */
    inline position getPos() const { return m_position; };
    //! Struktura przechowująca informacje o kolizji obiektu
    hitInfo m_hitInfo;
    //! Funkcja zwracająca id obiektu
    /**
     * @return Unikalne ID obiektu
     */
    inline int getID() { return m_ID; };
    //! Funkcja zwracająca pole m_markedForDelete
    /**
     * @return Zwraca informację, czy obiekt powinien być usunięty
     */
    inline bool getMarkForDelete() { return m_markedForDelete; };
    //! Funkcja zwracająca pole m_reset
    /**
     * @return Zwraca informację, czy zresetować obiekt
     */
    inline bool getReset() { return m_reset;};
    //! Funkcja zwracająca pole m_nextStage
    /**
     * @return Zwraca informację, czy przejść do następnego etapu
     */
    inline bool getNextStage() {return m_nextStage;};
};