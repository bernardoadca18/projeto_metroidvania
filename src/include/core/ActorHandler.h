#ifndef ACTORHANDLER_H
#define ACTORHANDLER_H

#include "Actor.h"
#include "Player.h"
#include <vector>

class ActorHandler
{
    public:
        Player playerActor;
        AnimationRenderer playerActorIdleAnimationRenderer;
        AnimationRenderer playerActorMovingAnimationRenderer;
        
        ActorHandler() {};
        ~ActorHandler() {};
        
        void actorInitHandler();
        void actorUpdateHandler();
        void actorDrawHandler();
};

#endif