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
    this->velocityX = 0.0f;
    this->isMoving = false;
    this->animationRenderers.clear();
}

void Actor::init(const char* spritePath, float movementSpeed, int layer, bool hasGravity, float gravity, const bool isAnimated, float positionX, float positionY, float colliderWidth, float colliderHeight, float scaleX, float scaleY, int spriteRenderSize, float colliderOffsetX, float colliderOffsetY, Color colliderDebugColor)
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
    this->flipX = false;
    this->colliderWidth = colliderWidth;
    this->colliderHeight = colliderHeight;

    this->colliderOffsetX = colliderOffsetX;
    this->colliderOffsetY = colliderOffsetY;

    this->colliderOffsetX *= this->scaleX;
    this->colliderOffsetY *= this->scaleY;

    this->collider = (Rectangle){this->positionX, this->positionY, this->colliderWidth*scaleX, this->colliderHeight*scaleY};
    this->spriteRect = (Rectangle){0.0f, 0.0f, ((float)(this->spriteRenderSize)) * scaleX, ((float)(this->spriteRenderSize)) * scaleY};

    this->sprite = LoadTexture(spritePath);
}

void Actor::update(std::vector<Actor*>& actors)
{
    //std::cout << "Updating actor at position: (" << this->positionX << ", " << this->positionY << ")" << std::endl;

    this->applyGravity();
    this->updateCollider();
    //this->stateHandler();

    for (Actor* other : actors)
    {
        if (other != this && this->checkCollision(*other))
        {
            std::cout << "Colisão detectada entre os objetos nas posições: (" << this->positionX << ", " << this->positionY << ") e (" << other->getPositionX() << ", " << other->getPositionY() << ")" << std::endl;

            
        }
    }

    if (this->isAnimated && !this->animationRenderers.empty())
    {
        this->animationRenderers[this->animationState].update();
    }

    std::cout << "is colliding ? " << this->colliding << std::endl;
}

void Actor::draw()
{
    if(this->isAnimated && !this->animationRenderers.empty())
    {
        this->animationRenderers[this->animationState].draw((Vector2){this->positionX, this->positionY}, this->scaleX, this->scaleY, this->positionX, this->positionY, this->flipX);
    }
    else
    {
        DrawTextureRec(this->sprite, this->spriteRect, (Vector2){this->positionX, this->positionY}, WHITE); 
    }

    drawDebugCollider(this->colliderDebugColor);
    drawPositionPoint(GREEN);
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
    this->colliding = CheckCollisionRecs(this->collider, other.getCollider());
    return CheckCollisionRecs(this->collider, other.getCollider());
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

void Actor::drawDebugCollider(Color colliderColor)
{
    DrawRectangleLinesEx(this->collider, 1, colliderColor);
    Color colorTransparent = colliderColor;
    colorTransparent.a = 100; // Define a transparência
    DrawRectangleRec(this->collider, colorTransparent);
}

void Actor::drawPositionPoint(Color color) {
    DrawPixel(static_cast<int>(this->positionX), static_cast<int>(this->positionY), color);
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

float Actor::getVelocityX() const
{
    return this->velocityX;
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

bool Actor::getFlipX() const
{
    return this->flipX;
}

Color Actor::getColliderDebugColor() const
{
    return this->getColliderDebugColor();
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

void Actor::setFlipX(bool flipX)
{
    this->flipX = flipX;
}

bool Actor::getIsAnimated() const 
{
    return isAnimated;
}

void Actor::setIsAnimated(bool isAnimated) 
{
    this->isAnimated = isAnimated;
}

void Actor::setColliderDebugColor(Color colliderDebugColor)
{
    this->colliderDebugColor = colliderDebugColor;
}

void Actor::setVelocityX(float velocityX)
{
    this->velocityX = velocityX;
}

void Actor::setVelocityY(float velocityY)
{
    this->velocityY = velocityY;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////