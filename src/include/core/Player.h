#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "Keymap.h"

class Player : public Actor 
{
    private:
        Keymap keymap;

    public:
        Player() {};
        ~Player() {};

        void handleInput();
        void update();
        void stateHandler();
};

#endif