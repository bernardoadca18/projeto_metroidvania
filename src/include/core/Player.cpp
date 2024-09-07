#include "Player.h"

void Player::handleInput()
{
    if (keymap.getMoveRightKey())
    {
        this->transformPositionX(this->getMovementSpeed(), 1.0f);
        this->setMoving(true);
    }
    else if (keymap.getMoveLeftKey())
    {
        this->transformPositionX(this->getMovementSpeed(), -1.0f);
        this->setMoving(true);
    }
    else
    {
        this->setMoving(false);
    }
}

void Player::update() 
{
    this->handleInput();
    this->stateHandler();
    this->animationRenderers[this->getAnimationState()].update();
}

void Player::stateHandler()
{
    if (this->getMoving())
    {
        this->setAnimationState(1);
    }
    else
    {
        this->setAnimationState(0);
    }
}