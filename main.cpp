/*
 *
 * Testing documents for SDL2 Engine
 * 2/10/2015
 *
 * Author: Nathan Hughes /w help from lazyfoo and SDL offical book
 * 
 *
 */

//Using SDL and standard IO
#include <SDL.h>
#include "Game.h"

//Screen dimension constants
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;


//Game object
Game *g_game = 0;

int main(int argc, char *args[]) {

    g_game = new Game();

    //init the window to be centered and with the size declared
    g_game->init("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                 WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    //while game is running, perform the loop
    while(g_game->running()){
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }

    //when game loop exits, clean up
    g_game->clean();


    return 0;
}