#ifndef KEYMAP_H
#define KEYMAP_H

#include "raylib.h"

class Keymap 
{
    public:
        Keymap() {};
        ~Keymap() {};
        bool getMoveRightKey() { return (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)); }
        bool getMoveLeftKey() { return (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)); }
        bool getUpKey() { return (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)); }
        bool getCrouchKey() { return (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)); }
        bool getJumpKey() { return (IsKeyDown(KEY_SPACE)); }
        bool getAttackKey() { return (IsKeyDown(KEY_K) || IsKeyDown(KEY_X)); }
        bool getSecondaryKey() { return (IsKeyDown(KEY_L) || IsKeyDown(KEY_Z)); }
        bool getInteractKey() { return (IsKeyDown(KEY_I)) || IsKeyDown(KEY_E); }
};
    

#endif