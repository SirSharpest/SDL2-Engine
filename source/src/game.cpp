#include <SDL2/SDL.h>
#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

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
    Input input;

    //Event that has happened for this particular frame
    SDL_Event event;

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
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true){
            return; 
        }
    }

}

void Game::draw(Graphics &graphics){

}

void Game::update(float elapsedTime){

}

