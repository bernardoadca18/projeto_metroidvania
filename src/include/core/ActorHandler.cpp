#include "ActorHandler.h"
#include "Actor.h"

void ActorHandler::actorInitHandler()
{
    int playerSpriteSize {64};

    this->playerActorIdleAnimationRenderer.init("src/assets/sprites/characters/main_character/spr_main_char_idle.png", 110.0f, 20.0f, playerSpriteSize, 5);
    this->playerActorMovingAnimationRenderer.init("src/assets/sprites/characters/main_character/spr_main_char_running.png", 110.0f, 20.0f, playerSpriteSize, 4);

    playerActor.init(2.5f, 0, false, 9.8f, true, 0.0f, 0.0f, 16.0f, 55.0f, playerSpriteSize);

    playerActor.addAnimationRenderer(this->playerActorIdleAnimationRenderer);
    playerActor.addAnimationRenderer(this->playerActorMovingAnimationRenderer);


    actors.push_back(&playerActor);
}

void ActorHandler::actorUpdateHandler()
{
    for (Actor* actor : actors)
    {
        actor->update(actors);
    }
}

void ActorHandler::actorDrawHandler()
{
    for (Actor* actor : actors)
    {
        actor->draw();
    }
}