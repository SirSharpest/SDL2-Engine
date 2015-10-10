//
// Created by nathan on 10/10/15.
//

#include "Game.h"
#include <SDL.h>

bool Game::init(const char *title, int xpos, int ypos,
                int height, int width, int flags) {

    //init SDL (Doing all for now so not to have to init all elements)
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        //If success then create the window!
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     height, width, flags);

        //if the window creation succeeded create the renderer
        if(m_pWindow != 0) {

            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            //if the renderer was created
            if(m_pRenderer != 0){
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255
                ,255,255);
            }
            else{
                //renderer has failed
                return false;
            }
        }
        else {
            return false; //window has failed at init
        }
    }
    else{
        return false; // SDL init has failed
    }

    //if it gets to here, then all is well
    //start the main loop
    m_bRunning = true;

    return true;

}

void Game::render(){

    //clear the renderer
    SDL_RenderClear(m_pRenderer);

    //draw to screen
    SDL_RenderPresent(m_pRenderer);

}

void Game::handleEvents(){

    SDL_Event event;
    if(SDL_PollEvent(&event)){

        switch(event.type){

            case SDL_QUIT:
                m_bRunning = false;
                break;

            default:
                break;


        }

    }

}

void Game::clean(){

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();

}
