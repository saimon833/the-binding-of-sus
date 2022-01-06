#include "game.h"
#include <cstdlib>
Game *game = nullptr;

int main(/*int argc, char *argv[]*/) {
    srand(time(NULL));
    const int FPS = 120;
    const double frameDelay = 1000. / FPS;
    Uint32 frameStart;
    float frameTime = 0.0f;
    game = new Game();
    game->init("Sussy Wussy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 650, false);
    while (game->running()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update(frameDelay);
        game->render();
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
            frameTime = frameDelay;
        }
    }
    game->clean();
    return 0;
}