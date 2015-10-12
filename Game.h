//
// Created by nathan on 10/10/15.
//

#ifndef SDL2_GAME_H
#define SDL2_GAME_H

#include <SDL.h>


class Game {

public:

    Game() {}
    ~Game() {}

    //set the running variable to true
    bool init(const char *title, int xpos, int ypos,
              int height, int width, int flags);

    void render();
    void update(){}
    void handleEvents();
    void clean();

    //a function to access the private running variable
    bool running() {return m_bRunning;}



private:

    //The window we'll be rendering to
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    //Image and texture pointers and variables
    SDL_Texture* m_pTexture; // new SDL_Texture
    SDL_Rect m_sourceRectangle; // the first rectangle
    SDL_Rect m_destinationRectangle; //another rectangle


    bool m_bRunning;

};


#endif //SDL2_GAME_H
