#include "ActorHandler.h"
#include "Actor.h"

void ActorHandler::actorInitHandler()
{
    this->playerActorIdleAnimationRenderer.init("src/assets/sprites/characters/main_character/sprsh_char_idle.png", 110.0f, 20.0f, 64, 1);
    this->playerActorMovingAnimationRenderer.init("src/assets/sprites/characters/main_character/sprsh_char_running.png", 110.0f, 20.0f, 64, 15);
    playerActor.init(2.5f);
    playerActor.addAnimationRenderer(this->playerActorIdleAnimationRenderer);
    playerActor.addAnimationRenderer(this->playerActorMovingAnimationRenderer);
}

void ActorHandler::actorUpdateHandler()
{
    playerActor.update();
}

void ActorHandler::actorDrawHandler()
{
    playerActor.draw();
}