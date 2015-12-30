//
// Created by nathan on 21/12/15.
//

#ifndef SDL2_GAME_H
#define SDL2_GAME_H

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


};


#endif //SDL2_GAME_H
