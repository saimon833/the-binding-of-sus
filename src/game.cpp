#include "game.h"
#include "player.h"
#include "boss.h"
#include "obstacle.h"
#include "params.h"
#include "projectile.h"
#include "wall.h"
GameObject *player, *enemy;

Game::Game() {
}
Game::~Game() {
    delete m_b2world;
    for (auto object : m_objects) {
        delete object;
    }
}
void Game::init(const char *title, int xpos, int ypos, bool fullscreen) {
    Parameters params;
    m_commonResources.gameProperties = params.getProperties();
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialised " << std::endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, m_commonResources.gameProperties.window_w, m_commonResources.gameProperties.window_h, flags);
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

    m_objects.push_back(new Wall(m_b2world, -1, 0, m_commonResources.gameProperties.window_h, 0));
    m_objects.push_back(new Wall(m_b2world, m_commonResources.gameProperties.window_w + 1, 0, m_commonResources.gameProperties.window_h, 0));
    m_objects.push_back(new Wall(m_b2world, 1, m_commonResources.gameProperties.window_h, 0, m_commonResources.gameProperties.window_w - 2));
    m_objects.push_back(new Wall(m_b2world, 1, -1, 0, m_commonResources.gameProperties.window_w - 2));
    player = new Player(m_b2world, "assets/player.png", m_renderer, m_commonResources, 0, 0);
    m_objects.push_back(player);
    enemy = new Boss(m_b2world,"assets/enemy.png",m_renderer,m_commonResources,750, 550);
    m_objects.push_back(enemy);

    for (int i = 0; i < 10; i++) {
        m_objects.push_back(new Obstacle(m_b2world, m_renderer, m_commonResources));
        SDL_Delay(75);
    }
}
void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) { // ustawianie nacisniecia klawiszy
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
                case SDLK_UP:
                    m_commonResources.keyState.shootUp = 1;
                case SDLK_DOWN:
                    m_commonResources.keyState.shootDown = 1;
                case SDLK_LEFT:
                    m_commonResources.keyState.shootLeft = 1;
                case SDLK_RIGHT:
                    m_commonResources.keyState.shootRight = 1;
                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) { // ustawianie puszczenia klawiszy
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
                case SDLK_UP:
                    m_commonResources.keyState.shootUp = 0;
                case SDLK_DOWN:
                    m_commonResources.keyState.shootDown = 0;
                case SDLK_LEFT:
                    m_commonResources.keyState.shootLeft = 0;
                case SDLK_RIGHT:
                    m_commonResources.keyState.shootRight = 0;
                default:
                    break;
            }
            break;

        default:
            break;
    }
}
void Game::update(float frameTime) {
    m_commonResources.timeStep=frameTime;
    m_physicsTimeAccumulator += frameTime;
    while (m_physicsTimeAccumulator > m_physicsDelay) {
        m_b2world->Step(m_timeStep, 8, 3);
        m_physicsTimeAccumulator -= m_physicsDelay;
        m_b2world->ClearForces();
    }
    spawnProjectile(frameTime);
    for (auto object : m_objects) {
        object->update();
    }
}
void Game::render() {
    SDL_RenderClear(m_renderer);
    // dodac rzeczy do renderowania
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
void Game::spawnProjectile(float frameTime) {
    int xpos = player->getPosX();
    int ypos = player->getPosY();
    m_shootingTimeAccumulator += frameTime;
    if ((m_shootingTimeAccumulator > m_shootingDelay) && (m_commonResources.keyState.shootUp || m_commonResources.keyState.shootDown || m_commonResources.keyState.shootLeft || m_commonResources.keyState.shootRight)) {
        m_objects.push_back(new Projectile(m_b2world, m_renderer, m_commonResources, xpos, ypos));
        std::cout << "shot fired" << std::endl;
        m_shootingTimeAccumulator = 0;
    }
}