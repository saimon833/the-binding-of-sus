#pragma once
#include "game_object.h"
#include "texture_manager.h"
//!Klasa abstrakcyjna służąca do tworzenia obiektów gracza oraz wroga
class Actor : public GameObject {
   protected:
    //! Wskaźnik do tekstury SDL_Texture
    SDL_Texture *m_objTexture;
    //! Obiekty służące do renderowania tekstury
    SDL_Rect m_srcRec, m_dstRec;
    //! Wskaźnik do renderera SLD_Renderer
    SDL_Renderer *m_renderer;
    //! Wskaźnik do ciała fizycznego z silnika Box2D
    b2Body *m_body;
    //! Struktura przechowująca pozycję obiektu
    position m_startPosition;
    /* data */
    //! Funkcja służąca do zaktualizowania pozycji gracza podczas każdego ticku
    virtual void updatePosition();
    //! Funckja służąca do zresetowania pozycji obiektu.
    void resetBodyPosition();

   public:
    //! KOnstruktor
    Actor(){};
    //! Destruktor
    virtual ~Actor(){};
    //! Funkcja służąca do przekazania do renderera parametrów tekstury
    virtual void render() override;
    //! Funckja wirtualna służąca do zaktualizowania stanu obiektu
    virtual void update() = 0;
    //! Funkcja wirtualna służąca do zresetowania stanu obiektu
    virtual void reset() = 0;
    //! Funckja wirtualna służąca do wywołania następnego etapu
    virtual void nextStage() = 0;
};
