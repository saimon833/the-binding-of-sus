#include "actor.h"
Actor::Actor(const char* texture_sheet, SDL_Renderer* ren,CommonResources &commonResources, int x, int y){
    m_renderer = ren;
    m_objTexture = TextureManager::LoadTexture(texture_sheet,ren);
    m_xpos=x;
    m_ypos=y;
    GameObject::m_commonResources=&commonResources;
    m_srcRec.h = 32;
    m_srcRec.w = 32;
    m_srcRec.x = 0;
    m_srcRec.y = 0;
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.w = m_srcRec.w*2;
    m_dstRec.h = m_srcRec.h*2;
}
void Actor::update(){
    if(m_commonResources->keyState.moveUp){
        m_ypos-=1;
    }
    else if(m_commonResources->keyState.moveDown){
        m_ypos+=1;
    }
    if(m_commonResources->keyState.moveLeft){
        m_xpos-=1;
    }
    if(m_commonResources->keyState.moveRight){
        m_xpos+=1;
    }
    
    m_dstRec.x = m_xpos;
    m_dstRec.y = m_ypos;
    m_dstRec.w = m_srcRec.w*2;
    m_dstRec.h = m_srcRec.h*2;
}
void Actor::render(){
    SDL_RenderCopy(m_renderer, m_objTexture, &m_srcRec, &m_dstRec);
}