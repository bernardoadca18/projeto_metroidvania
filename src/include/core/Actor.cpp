#include "Actor.h"
#include "stdio.h"
#include <vector>


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

void Actor::init(float movementSpeed, int layer, bool hasGravity = true, float gravity = 9.8f)
{
    this->animationState =  0;
    this->animationStatesCount = 1;
    this->movementSpeed = movementSpeed;
    this->collider = (Rectangle){this->positionX, this->positionY, 1.0f, 1.0f};
}

void Actor::update(std::vector<Actor>& actors)
{
    this->applyGravity();

    for (Actor& other : actors)
    {
        if (&other != this && this->checkCollision(other))
        {

            this->velocityY = 0;
        }
    }

    this->animationRenderers[this->animationState].update();
}

void Actor::draw()
{
    this->animationRenderers[this->animationState].draw((Vector2){this->positionX, this->positionY});
}

void Actor::applyGravity()
{
    if (this->hasGravity)
    {
        this->velocityY += this->gravity * GetFrameTime();
        this->positionY += this->velocityY;
    }
}

bool Actor::checkCollision(Actor& other)
{
    // Só verifica colisões em layers compatíveis
    if (this->layer == other.getLayer())
    {
        return CheckCollisionRecs(this->collider, other.getCollider());
    }
    return false;
}

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