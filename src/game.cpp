#include "game.h"
#include "texturemanager.h"
SDL_Texture* player_tex;
SDL_Rect srcR, destR;


Game::Game(){

}
Game::~Game(){

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags=0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Subsystems Initialised "<< std::endl;
        window = SDL_CreateWindow(title,xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"Window created"<<std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Renderer created"<<std::endl;
        is_running=true;
    }
    else
        is_running = false;
    player_tex = TextureManager::LoadTexture("assets/player.png",renderer);
    
    
}
void Game::handle_events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            is_running=false;
            break;
        default:
            break;
    }
}
void Game::update(){
    cnt+=1;
    destR.h=64;
    destR.w=64;
    destR.x=cnt;
}
void Game::render(){
    SDL_RenderClear(renderer);
    //dodac rzeczy do renderowania
    SDL_RenderCopy(renderer,player_tex,NULL,&destR);
    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned"<<std::endl;
}