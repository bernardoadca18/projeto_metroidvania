#ifndef ACTOR_H
#define ACTOR_H

#include "raylib.h"
#include "AnimationRenderer.h"
#include <vector>

class Actor
{
    protected:
        std::vector<AnimationRenderer> animationRenderers;
    
    private:
        int spriteRenderSize;
        int animationState;
        int animationStatesCount;
        float movementSpeed;
        float positionX;
        float positionY;
        bool isMoving;
        bool isAnimated;
        float scaleX;
        float scaleY;
        int collisionWidth;
        int collisionHeight;
        bool flipX;

        // Variáveis de gravidade/colisao
        int layer;
        bool hasGravity;
        float gravity;
        float velocityY;
        float colliderWidth;
        float colliderHeight;
        float colliderOffsetX;
        float colliderOffsetY;
        Rectangle collider;

    public:
        Actor();
        Actor(float positionX, float positionY);
        ~Actor() {};

        void init(float movementSpeed, int layer, bool hasGravity, float gravity, const bool isAnimated, float positionX, float positionY, float colliderWidth, float colliderHeight, float scaleX, float scaleY, int spriteRenderSize, float colliderOffsetX, float colliderOffsetY);
        virtual void update(std::vector<Actor*>& actors);
        void updateCollider();
        void draw();
        void drawSprite();
        void applyGravity();
        bool checkCollision(Actor& other);

        void addAnimationRenderer(AnimationRenderer animationRenderer);
        void transformPositionX(float amount, float signal);
        void transformPositionY(float amount, float signal);
        //void stateHandler();

        // Debug
        void drawDebugCollider();

        // Getters
        int getAnimationState() const;
        float getPositionX() const;
        float getPositionY() const;
        float getMovementSpeed() const;
        bool getMoving();

        int getLayer() const;
        bool getHasGravity() const;
        Rectangle getCollider() const;
        float getVelocityY() const;
        float getScaleX() const;
        float getScaleY() const;
        bool getFlipX() const;
        

        // Setters
        void setAnimationState(int animationState);
        //void setAnimationRenderer();
        void setPosition(float positionX, float positionY);
        void setPositionX(float positionX);
        void setPositionY(float positionY);
        void setMoving(bool isMoving);

        void setLayer(int layer);
        void setHasGravity(bool hasGravity);
        void setGravity(float gravity);
        void setCollider(int colliderWidth, int colliderHeight);
        void setCollider(float colliderWidth, float colliderHeight);
        void setScaleX(float scaleX);
        void setScaleY(float scaleY);
        void setFlipX(bool flipX);

};

#endif // ACTOR_H