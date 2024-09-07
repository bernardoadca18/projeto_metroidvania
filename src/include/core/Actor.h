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
        int animationState;
        int animationStatesCount;
        float movementSpeed;
        float positionX;
        float positionY;
        bool isMoving;

        int collisionWidth;
        int collisionHeight;

        // Variáveis de gravidade/colisao
        int layer;
        bool hasGravity;
        float gravity;
        float velocityY;
        Rectangle collider;

    public:
        Actor();
        Actor(float positionX, float positionY);
        ~Actor() { };

        void init(float movementSpeed, int layer, bool hasGravity = true, float gravity = 9.8f);
        void update(std::vector<Actor>& actors);
        void draw();
        void applyGravity();
        bool checkCollision(Actor& other);

        void addAnimationRenderer(AnimationRenderer animationRenderer);
        void transformPositionX(float amount, float signal);

        // Getters
        int getAnimationState() const;
        float getPositionX() const;
        float getPositionY() const;
        float getMovementSpeed() const;
        bool getMoving();

        int getLayer() const;
        bool getHasGravity() const;
        Rectangle getCollider() const;

        // Setters
        void setAnimationState(int animationState);
        void setAnimationRenderer();
        void setPosition(float positionX, float positionY);
        void setPositionX(float positionX);
        void setPositionY(float positionY);
        void setMoving(bool isMoving);

        void setLayer(int layer);
        void setHasGravity(bool hasGravity);
        void setGravity(float gravity);
        void setCollider(Rectangle collider);
};

#endif // ACTOR_H