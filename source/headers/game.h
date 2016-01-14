//
// Created by nathan on 21/12/15.
//

#pragma once

#include "sprite.h"

//Forward declaring graphics
class Graphics;

class Game {

public:
    Game();
    ~Game();

private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite _player;

};



