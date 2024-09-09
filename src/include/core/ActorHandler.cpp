#include "ActorHandler.h"
#include "Actor.h"
#include <stdio.h>

void ActorHandler::actorInitHandler()
{
    struct PlayerActorInfo 
    {
        int playerSpriteSize {64};
        float playerSpriteScaleX {2.0f};
        float playerSpriteScaleY {2.0f};
        float playerMovementSpeed {8.0f};
        int playerLayer {0};
        bool playerHasGravity {false};
        float playerGravity {9.8f};
        bool playerIsAnimated {true};
        float playerPositionX {0.0f};
        float playerPositionY {0.0f};
        float playerColliderWidth {16.0f};
        float playerColliderHeight {52.0f};
        float playerColliderOffsetX {8.0f};
        float playerColliderOffsetY {20.0f};
    } playerActorInfo;

    playerActorInfo.playerPositionX = 320.0f;
    playerActorInfo.playerPositionY = 280.0f;

    // Inicializando os renderers
    this->playerActorIdleAnimationRenderer.init("src/assets/sprites/characters/main_character/spr_main_char_idle.png", playerActorInfo.playerSpriteSize, 5);
    this->playerActorMovingAnimationRenderer.init("src/assets/sprites/characters/main_character/spr_main_char_running.png", playerActorInfo.playerSpriteSize, 8);

    // Inicializando o playerActor (objeto que é responsável pelo controle do jogador, mesma coisa do actor normal praticamente, só que tem a função de input)
    this->playerActor.init(playerActorInfo.playerMovementSpeed, playerActorInfo.playerLayer, playerActorInfo.playerHasGravity, playerActorInfo.playerGravity, playerActorInfo.playerIsAnimated, playerActorInfo.playerPositionX, playerActorInfo.playerPositionY, playerActorInfo.playerColliderWidth, playerActorInfo.playerColliderHeight, playerActorInfo.playerSpriteScaleX, playerActorInfo.playerSpriteScaleY, playerActorInfo.playerSpriteSize, playerActorInfo.playerColliderOffsetX, playerActorInfo.playerColliderOffsetY);

    // Adicionando os animationrenderers ao playeractor.
    playerActor.addAnimationRenderer(this->playerActorIdleAnimationRenderer);
    playerActor.addAnimationRenderer(this->playerActorMovingAnimationRenderer);

    // Adicionando o playerActor a lista de actors.
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