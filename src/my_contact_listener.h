#pragma once
#include "resources.h"
//! Funckja odpowiedzialna za detekcje kolizji
class MyContactListener : public b2ContactListener {
    //! Funkcja wywołująca się, gdy dwa obiekty się zderzą
    void BeginContact(b2Contact *contact);
    //! Funckja wywołująca się, gdy dwa obiekty przestaną się zderzać
    void EndContact(b2Contact *contact);
};
