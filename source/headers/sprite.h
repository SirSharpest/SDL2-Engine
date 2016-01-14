//
// Created by nathan on 1/14/16.
//

#pragma once


#include "graphics.h"
#include <SDL2/SDL.h>

class Sprite {

public:
    Sprite();

    Sprite(Graphics &graphics, const std::string & filePath, int sourceX, int sourceY,
    int width, int height, float posX, float posY);

    virtual ~Sprite();
    virtual void update();

    void draw(Graphics &graphics, int x, int y);


private:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;

    float _x, _y;
};



