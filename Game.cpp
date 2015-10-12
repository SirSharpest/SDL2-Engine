//
// Created by nathan on 10/10/15.
//

#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

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
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0
                ,0,255);
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

    //image loading stuff
    SDL_Surface* pTempSurface = IMG_Load("resources/images/scottRunning.png");
    if(pTempSurface == NULL){return false;}
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
                                              pTempSurface);

    SDL_FreeSurface(pTempSurface);

    m_sourceRectangle.w = 108;
    m_sourceRectangle.h = 140;



    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;

    //end of image stuff




    return true;

}

void Game::render(){

    //clear the renderer
    SDL_RenderClear(m_pRenderer);

    //image loads here

    //Display normal
    //SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle,
    //&m_destinationRectangle);

    //Flipped display
    SDL_RenderCopyEx(m_pRenderer, m_pTexture,
    &m_sourceRectangle, &m_destinationRectangle, 0,0,
    SDL_FLIP_HORIZONTAL);

    //draw to screen
    SDL_RenderPresent(m_pRenderer);

}

void Game::update() {

    m_sourceRectangle.x = 108 * int(((SDL_GetTicks() / 100) % 6));

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
