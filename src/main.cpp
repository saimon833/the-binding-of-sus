#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[]){

    const int FPS = 165;
    const double frameDelay = 1000/(double)FPS;
    Uint32 frameStart;
    float frameTime=0.0f;

    game = new Game();
    game->init("dupa",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600,false);
    while(game->running()){
        frameStart=SDL_GetTicks();
        game->handle_events();
        game->update(frameTime);
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay>frameTime)
            SDL_Delay(frameDelay-frameTime);
    }

    game->clean();


    return 0;
}