#include "Player.h"
#include "Game.h"

void Player::handleInput()
{
    if (keymap.getMoveRightKey())
    {
        this->setVelocityX(this->getMovementSpeed());
        this->horizontalInput = 1.0f;
        this->setMoving(true);
        this->setFlipX(false);
    }
    else if (keymap.getMoveLeftKey())
    {
        this->setVelocityX(this->getMovementSpeed());
        this->horizontalInput = -1.0f;
        this->setMoving(true);
        this->setFlipX(true);
    }
    else
    {
        this->setVelocityX(0.0f);
        this->setMoving(false);
    }

    this->transformPositionX(this->getVelocityX(), this->horizontalInput);
}

void Player::update(std::vector<Actor*> & actors) 
{
    this->handleInput();
    Actor::update(actors);
    
    if (this->Actor::getIsAnimated())
    {
        this->stateHandler();
        this->animationRenderers[this->getAnimationState()].update();
    }
    //std::cout << "player update: posX=" << this->getPositionX() << ", posY=" << this->getPositionY() << ", velY=" << this->getVelocityY() << std::endl;
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