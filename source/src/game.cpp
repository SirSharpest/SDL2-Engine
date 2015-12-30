#include <SDL2/SDL.h>
#include "../headers/game.h"
#include "../headers/graphics.h"

/**
 * Game class
 * Holds information for the main game loop
 */


Game::Game(){
    //Load all the things
    SDL_Init(SDL_INIT_EVERYTHING);

    //Calls main loop
    this->gameLoop();
}

Game::~Game(){

}


void Game::gameLoop(){

    Graphics graphics;

    //Event that has happened for this particular frame
    SDL_Event event;

    while(true){
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                return;
        }
    }

}

void Game::draw(Graphics &graphics){

}

void Game::update(float elapsedTime){

}

