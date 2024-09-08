#include "Player.h"
#include "Game.h"
#include <iostream>

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

void Player::update(std::vector<Actor*> & actors) 
{
    this->handleInput();
    Actor::update(actors);
    this->stateHandler();
    this->animationRenderers[this->getAnimationState()].update();
    std::cout << "player update: posX=" << this->getPositionX() << ", posY=" << this->getPositionY() << ", velY=" << this->getVelocityY() << std::endl;
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