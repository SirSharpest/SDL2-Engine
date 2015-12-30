#include "../headers/input.h"

/*
 * Keeps track of keyboard state
 */

//This function is called at the beginning of each new frame
//to reset keys that are not relevent
void Input::beginNewFrame() {

    //clear pressed and released
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();

}

//Called when a key is pressed
void Input::keyDownEvent(const SDL_Event &event) {

    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;

}

//Called when key is released
void Input::keyUpEvent(const SDL_Event &event) {

    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;

}

//Check if certain key was pressed for this fra,e
bool Input::wasKeyPressed(SDL_Scancode key) {

    return this->_pressedKeys[key];

}

//check if key was released
bool Input::wasKeyReleased(SDL_Scancode key) {

    return this->_releasedKeys[key];

}

//Check if a key is currently being held
bool Input::isKeyHeld(SDL_Scancode key) {

    return this->_heldKeys[key];

}