#ifndef ACTORHANDLER_H
#define ACTORHANDLER_H

#include "Actor.h"
#include "Player.h"
#include <vector>

class ActorHandler
{
    private:
        Player playerActor;
        AnimationRenderer playerActorIdleAnimationRenderer;
        AnimationRenderer playerActorMovingAnimationRenderer;
        
    public:
        ActorHandler() {};
        ~ActorHandler() {};
        
        void actorInitHandler();
        void actorUpdateHandler();
        void actorDrawHandler();
};

#endif