#include "game_object.h"
#include "texture_manager.h"
GameObject::GameObject(const char* texture_sheet, SDL_Renderer* ren, int x, int y){
    renderer = ren;
    obj_texture = TextureManager::LoadTexture(texture_sheet,ren);
    xpos=x;
    ypos=y;
}
void GameObject::update(){

    xpos++;
    ypos++;

    src_rec.h = 32;
    src_rec.w = 32;
    src_rec.x = 0;
    src_rec.y = 0;
    dst_rec.x = xpos;
    dst_rec.y = ypos;
    dst_rec.w = src_rec.w*2;
    dst_rec.h = src_rec.h*2;
}
void GameObject::render(){
    SDL_RenderCopy(renderer, obj_texture, &src_rec, &dst_rec);
}
