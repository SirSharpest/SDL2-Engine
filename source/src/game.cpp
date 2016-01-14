#include <SDL2/SDL.h>
#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

/**
 * Game class
 * Holds information for the main game loop
 */

namespace {

    const int FPS = 50;

    //Max amount of time that a frame can last
    const int MAX_FRAME_TIME = 1000 / FPS;
}


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
    Input input;

    //Event that has happened for this particular frame
    SDL_Event event;


    int LAST_UPDATE_TIME = SDL_GetTicks();

    //Start the game loop
    while(true){

        //Begin a new frame at the start of each loop
        input.beginNewFrame();

        if(SDL_PollEvent(&event)){
            //A key was pressed :D
            if(event.type == SDL_KEYDOWN){
                //Checks that a key is not a repeated press
                if(event.key.repeat == 0){
                    input.keyDownEvent(event);
                }
            }// if a key was released
            else if (event.type == SDL_KEYUP){
                input.keyUpEvent(event);
            }//if the user hits the exit button
            else if (event.type == SDL_QUIT){
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
            return;
        }


        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
    }


}

void Game::draw(Graphics &graphics){

}

void Game::update(float elapsedTime){

}

