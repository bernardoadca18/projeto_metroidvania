#ifndef ACTORHANDLER_H
#define ACTORHANDLER_H

#include "Actor.h"
#include "Player.h"
#include <vector>

class ActorHandler
{
    private:
        std::vector<Actor*> actors;
        
        Player playerActor;
        AnimationRenderer playerActorIdleAnimationRenderer;
        AnimationRenderer playerActorMovingAnimationRenderer;

        Actor groundPlaceholder;
        
        
    public:
        ActorHandler() {};
        ~ActorHandler() {};
        
        void actorInitHandler();
        void actorUpdateHandler();
        void actorDrawHandler();
};

#endif