//
// Created by nathan on 30/12/15.
//

#ifndef SDL2_INPUT_H
#define SDL2_INPUT_H

#include <map>
#include <SDL2/SDL.h>

class Input{

public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);

private:

    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;


};




#endif //SDL2_INPUT_H
