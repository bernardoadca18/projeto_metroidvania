#include "Actor.h"
#include <vector>
#include <iostream>

Actor::Actor()
{
    this->positionX = 0.0f;
    this->positionY = 0.0f;

    this->movementSpeed = 0.0f;
    this->spriteRenderSize = 0;
    this->layer = 0;
    this->hasGravity = false;
    this->gravity = 0.0f;
    this->isAnimated = false;
    this->scaleX = 1.0f;
    this->scaleY = 1.0f;
    this->colliderWidth = 0.0f;
    this->colliderHeight = 0.0f;
    this->colliderOffsetX = 0.0f;
    this->collider = {0.0f, 0.0f, 0.0f, 0.0f};
    this->animationState = 0;
    this->animationStatesCount = 1;
    this->velocityY = 0.0f;
    this->isMoving = false;
    this->animationRenderers.clear();
}

void Actor::init(float movementSpeed, int layer, bool hasGravity, float gravity, const bool isAnimated, float positionX, float positionY, float colliderWidth, float colliderHeight, float scaleX, float scaleY, int spriteRenderSize, float colliderOffsetX, float colliderOffsetY)
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
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->colliderWidth = colliderWidth;
    this->colliderHeight = colliderHeight;

    this->colliderOffsetX = colliderOffsetX;
    this->colliderOffsetY = colliderOffsetY;

    this->colliderOffsetX *= this->scaleX;
    this->colliderOffsetY *= this->scaleY;

    this->collider = (Rectangle){this->positionX, this->positionY, this->colliderWidth*scaleX, this->colliderHeight*scaleY};
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
    this->animationRenderers[this->animationState].draw((Vector2){this->positionX, this->positionY}, this->scaleX, this->scaleY, this->positionX, this->positionY);

    drawDebugCollider();
}

void Actor::updateCollider()
{


    collider.x = this->getPositionX() - this->colliderOffsetX;// - this->colliderOffsetX;// + this->colliderOffsetX;
    collider.y = this->getPositionY() - this->colliderOffsetY;// + this->colliderOffsetY;

    collider.width = this->colliderWidth * this->scaleX;
    collider.height = this->colliderHeight * this->scaleY;
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

float Actor::getScaleX() const
{
    return this->scaleX;
}

float Actor::getScaleY() const
{
    return this->scaleY;
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

void Actor::setScaleX(float scaleX)
{
    this->scaleX = scaleX;
}

void Actor::setScaleY(float scaleY)
{
    this->scaleY = scaleY;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////