#include "game.h"
#include "actor.h"
GameObject* player;
//GameObject* enemy;

Game::Game(){

}
Game::~Game(){
    delete m_b2world;
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags=0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Subsystems Initialised "<< std::endl;
        m_window = SDL_CreateWindow(title,xpos, ypos, width, height, flags);
        if(m_window){
            std::cout<<"Window created"<<std::endl;
        }
        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if(m_renderer)
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
            std::cout<<"Renderer created"<<std::endl;
        m_isRunning=true;
    }
    else
        m_isRunning = false;
    b2Vec2 gravity(0.0f, 0.0f);
    m_b2world=new b2World(gravity);
    
    player=new Actor(m_b2world,"assets/player.png",m_renderer,m_commonResources,100,100);
    //enemy=new Actor("assets/enemy.png",renderer,50,50);
}
void Game::handle_events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            m_isRunning=false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {        //ustawianie nacisniecia klawiszy
                case SDL_SCANCODE_LEFT:
                    m_commonResources.keyState.moveLeft=1;
                    break;
                case SDL_SCANCODE_RIGHT:
                    m_commonResources.keyState.moveRight=1;
                    break;
                case SDL_SCANCODE_UP:
                    m_commonResources.keyState.moveUp=1;
                    break;
                case SDL_SCANCODE_DOWN:
                    m_commonResources.keyState.moveDown=1;
                    break;
                default:
                    break;
                } 
            //std::cout<<"Key press detected"<<std::endl;
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {        //ustawianie puszczenia klawiszy
                case SDL_SCANCODE_LEFT:
                    m_commonResources.keyState.moveLeft=0;
                    break;
                case SDL_SCANCODE_RIGHT:
                    m_commonResources.keyState.moveRight=0;
                    break;
                case SDL_SCANCODE_UP:
                    m_commonResources.keyState.moveUp=0;
                    break;
                case SDL_SCANCODE_DOWN:
                    m_commonResources.keyState.moveDown=0;
                    break;
                default:
                    break;
                } 
            
            //std::cout<<"Key release detected"<<std::endl;
            break;

        default:
            break;
    }
}
void Game::update(float frameTime){
    //while(){
        m_b2world->Step(Game::timeStep, 8, 3);
        //boxStepClock -= stepDelay;
        m_b2world->ClearForces();
    //}
    player->update();
    //enemy->update();
    
    
}
void Game::render(){
    SDL_RenderClear(m_renderer);
    //dodac rzeczy do renderowania
    player->render();
    //enemy->render();
    SDL_RenderPresent(m_renderer);

}
void Game::clean(){
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Game cleaned"<<std::endl;
}