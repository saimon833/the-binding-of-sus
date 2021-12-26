#include "game.h"
#include "actor.h"
#include "wall.h"
GameObject *player;
GameObject *lwall, *rwall, *twall, *bwall;
// GameObject* enemy;

Game::Game() {
}
Game::~Game() {
    delete m_b2world;
    for (auto object : m_objects){
        delete object;
    }
}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialised " << std::endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_window) {
            std::cout << "Window created" << std::endl;
        }
        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if (m_renderer)
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        std::cout << "Renderer created" << std::endl;
        m_isRunning = true;
    } else
        m_isRunning = false;
    b2Vec2 gravity(0.0f, 0.0f);
    m_b2world = new b2World(gravity);

    player = new Actor(m_b2world, "assets/box.png", m_renderer, m_commonResources, 0, 0);
    lwall=new Wall(m_b2world,-1,0,height,0);
    rwall=new Wall(m_b2world,width+1,0,height,0);
    bwall=new Wall(m_b2world,1,height,0,width-2);
    twall=new Wall(m_b2world,1,-1,0,width-2);
    m_objects.push_back(player);
    //m_objects.push_back(lwall);
    m_commonResources.windowProperties.h=height;
    m_commonResources.windowProperties.w=width;
}
void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) { //ustawianie nacisniecia klawiszy
                case SDLK_a:
                    m_commonResources.keyState.moveLeft = 1;
                    break;
                case SDLK_d:
                    m_commonResources.keyState.moveRight = 1;
                    break;
                case SDLK_w:
                    m_commonResources.keyState.moveUp = 1;
                    break;
                case SDLK_s:
                    m_commonResources.keyState.moveDown = 1;
                    break;
                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) { //ustawianie puszczenia klawiszy
                case SDLK_a:
                    m_commonResources.keyState.moveLeft = 0;
                    break;
                case SDLK_d:
                    m_commonResources.keyState.moveRight = 0;
                    break;
                case SDLK_w:
                    m_commonResources.keyState.moveUp = 0;
                    break;
                case SDLK_s:
                    m_commonResources.keyState.moveDown = 0;
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
    }
}
void Game::update(float frameTime) {
    m_physicsTimeAccumulator += frameTime;
    while (m_physicsTimeAccumulator > m_physicsDelay) {
        m_b2world->Step(m_timeStep, 8, 3);
        m_physicsTimeAccumulator -= m_physicsDelay;
        m_b2world->ClearForces();
    }
    for (auto object : m_objects) {
        object->update();
    }
}
void Game::render() {
    SDL_RenderClear(m_renderer);
    //dodac rzeczy do renderowania
    for (auto object : m_objects) {
        object->render();
    }
    SDL_RenderPresent(m_renderer);
}
void Game::clean() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}