#include "Actor.h"
#include <vector>
#include <iostream>

Actor::Actor()
{
    this->positionX = 0.0f;
    this->positionY = 0.0f;
}

void Actor::init(float movementSpeed, int layer, bool hasGravity, float gravity, const bool isAnimated, float positionX, float positionY, float colliderWidth, float colliderHeight, int spriteRenderSize)
{
    this->animationState =  0;
    this->animationStatesCount = 1;
    this->movementSpeed = movementSpeed;
    this->spriteRenderSize = spriteRenderSize;
    this->layer = layer;
    this->hasGravity = hasGravity;
    this->gravity = gravity;
    this->isAnimated = isAnimated;
    this->positionX = positionX;
    this->positionY = positionY;
    this->colliderWidth = colliderWidth;
    this->colliderHeight = colliderHeight;

    this->colliderOffsetX = this->colliderWidth;

    this->collider = (Rectangle){this->positionX, this->positionY, this->colliderWidth, this->colliderHeight};
}

void Actor::update(std::vector<Actor*>& actors)
{
    this->applyGravity();
    this->updateCollider();
    //this->stateHandler();

    for (Actor* other : actors)
    {
        if (other != this && this->checkCollision(*other))
        {
            this->velocityY = 0;
        }
    }

    this->animationRenderers[this->animationState].update();
}

void Actor::draw()
{
    this->animationRenderers[this->animationState].draw((Vector2){this->positionX, this->positionY});

    drawDebugCollider();
}

void Actor::updateCollider()
{
    collider.x = this->getPositionX();
    collider.y = this->getPositionY();
}

void Actor::drawSprite()
{

}

//void Actor::stateHandler()
//{
//    if (this->getMoving())
//    {
//        this->setAnimationState(1);
//    }
//    else
//    {
//        this->setAnimationState(0);
//    }
//}

void Actor::applyGravity()
{
    if (this->hasGravity)
    {
        this->velocityY += this->gravity * GetFrameTime();
        this->transformPositionY((this->velocityY), 1.0f);
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

void Actor::transformPositionY(float amount, float signal)
{
    this->positionY += (amount)*(signal);
}

void Actor::drawDebugCollider()
{
    DrawRectangleLinesEx(this->collider, 1, GREEN);
    Color greenTransparent = GREEN;
    greenTransparent.a = 100; // Define a transparência
    DrawRectangleRec(this->collider, greenTransparent);
}






// Getters
int Actor::getAnimationState() const
{
    return this->animationState;
}

float Actor::getPositionX() const
{
    return this->positionX;
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

int Actor::getLayer() const
{
    return this->layer;
}

bool Actor::getHasGravity() const
{
    return this->hasGravity;
}

Rectangle Actor::getCollider() const
{
    return this->collider;
}

float Actor::getVelocityY() const
{
    return this->velocityY;
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

void Actor::setCollider(int colliderWidth, int colliderHeight)
{
    this->collider = (Rectangle){this->positionX, this->positionY, (float)colliderWidth, (float)colliderHeight};
}

void Actor::setCollider(float colliderWidth, float colliderHeight)
{
    this->collider = (Rectangle){this->positionX, this->positionY, colliderWidth, colliderHeight};
}

void Actor::setLayer(int layer)
{
    this->layer = layer;
}

void Actor::setHasGravity(bool hasGravity)
{
    this->hasGravity = hasGravity;
}

void Actor::setGravity(float gravity)
{
    this->gravity = gravity;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////