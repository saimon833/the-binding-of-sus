#pragma once
#include "resources.h"
class GameObject {
   protected:
    position m_position;
    static int m_nextID;
    const int m_ID;
    bool m_markedForDelete = 0;
    bool m_nextStage = 0;
    bool m_reset = 0;

   public:
    CommonResources *m_commonResources;
    GameObject();
    virtual ~GameObject(){};
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void reset() = 0;
    virtual void nextStage() = 0;
    inline position getPos() const { return m_position; };
    hitInfo m_hitInfo;
    inline int getID() { return m_ID; };
    inline bool getMarkForDelete() { return m_markedForDelete; };
    inline bool getReset() { return m_reset;};
    inline bool getNextStage() {return m_nextStage;};
};