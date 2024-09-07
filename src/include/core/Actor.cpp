#include "Actor.h"
#include "stdio.h"


Actor::Actor()
{
    this->positionX = 0.0f;
    this->positionY = 0.0f;
}

Actor::Actor(float positionX, float positionY)
{
    this->positionX = positionX;
    this->positionY = positionY;
}

void Actor::init(float movementSpeed)
{
    this->animationState =  0;
    this->animationStatesCount = 1;
    this->movementSpeed = movementSpeed;
}

void Actor::update()
{
    this->animationRenderers[this->animationState].update();
}

void Actor::draw()
{
    this->animationRenderers[this->animationState].draw((Vector2){this->positionX, this->positionY});
}

void Actor::destroy() {}

void Actor::addAnimationRenderer(AnimationRenderer animationRenderer)
{
    this->animationRenderers.push_back(animationRenderer);
}

void Actor::transformPositionX(float amount, float signal)
{
    this->positionX += (amount)*(signal);
}

// Getters
int Actor::getAnimationState() const
{
    return this->animationState;
}

float Actor::getPositionX() const
{
    return this->positionY;
}

float Actor::getPositionY() const
{
    return this->positionY;
}

float Actor::getMovementSpeed() const
{
    return this->movementSpeed;
}

bool Actor::getMoving()
{
    return this->isMoving;
}


// Setters
void Actor::setAnimationState(int animationState)
{
    this->animationState = animationState;
}

void Actor::setPosition(float positionX, float positionY)
{
    this->positionX = positionX;
    this->positionY = positionY;
}

void Actor::setPositionX(float positionX)
{
    this->positionX = positionX;
}

void Actor::setPositionY(float positionY)
{
    this->positionY = positionY;
}

void Actor::setMoving(bool isMoving)
{
    this->isMoving = isMoving;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////