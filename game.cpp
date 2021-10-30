#include "game.h"
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
    cnt=cnt+1;
    std::cout<<cnt<<std::endl;
}
void Game::render(){
    SDL_RenderClear(renderer);
    //dodac rzeczy do renderowania
    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned"<<std::endl;
}