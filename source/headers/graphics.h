//
// Created by nathan on 18/12/15.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>

//Forward declared pointers to these
struct SDL_Window;
struct SDL_Renderer;


class Graphics {

public:

    Graphics();
    ~Graphics();


private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;



};


#endif //SDL2_GRAPHICS_H
