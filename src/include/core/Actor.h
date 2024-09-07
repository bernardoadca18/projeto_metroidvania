#ifndef ACTOR_H
#define ACTOR_H

#include "raylib.h"
#include "AnimationRenderer.h"
#include <vector>

class Actor
{
    private:
        int animationState;
        int animationStatesCount;
        float movementSpeed;
        float positionX;
        float positionY;

        bool isMoving;

    public:
        std::vector<AnimationRenderer> animationRenderers;
        Actor();
        Actor(float positionX, float positionY);
        ~Actor() { this->destroy(); };

        void init(float movementSpeed);
        void update();
        void draw();
        void destroy();

        void addAnimationRenderer(AnimationRenderer animationRenderer);

        void transformPositionX(float amount, float signal);

        // Getters
        int getAnimationState() const;
        float getPositionX() const;
        float getPositionY() const;
        float getMovementSpeed() const;
        AnimationRenderer currentAnimationRenderer;
        bool getMoving();

        // Setters
        void setAnimationState(int animationState);
        void setAnimationRenderer();
        void setPosition(float positionX, float positionY);
        void setPositionX(float positionX);
        void setPositionY(float positionY);
        void setMoving(bool isMoving);
};

#endif // ACTOR_H