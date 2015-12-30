//
// Created by nathan on 18/12/15.
//

#include "../headers/graphics.h"
/*
 * Holds all information about graphics for the engine
 */

/*
 * Constructor for the
 * Graphics object
 *
 * Consider making this a singleton???
 */
Graphics::Graphics() {

    //TODO Const these widths and widths
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "SDL Engine");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}