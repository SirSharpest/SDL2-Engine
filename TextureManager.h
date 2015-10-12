//
// Created by nathan on 12/10/15.
//

#include <SDL.h>
#include <bits/stringfwd.h>
#include <map>


#ifndef SDL2_TEXTUREMANAGER_H
#define SDL2_TEXTUREMANAGER_H



class TextureManager {

public:

    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

    //draw functions
    void draw(std::string id, int x, int y, int width, int height,
    SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //draw frame
    void drawFrame(std::string id, int x, int y, int width, int height,
                   int currentRow, int currentFrame,
                   SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE );

    std::map<std::string, SDL_Texture*> m_textureMap;

};


#endif //SDL2_TEXTUREMANAGER_H
