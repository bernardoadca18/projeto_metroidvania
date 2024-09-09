#include "ActorHandler.h"
#include "Actor.h"

void ActorHandler::actorInitHandler()
{
    int playerSpriteSize {64};
    float playerSpriteScaleX {1.0f};
    float playerSpriteScaleY {1.0f};
    float playerMovementSpeed {2.5f};
    int playerLayer {0};
    bool playerHasGravity {false};
    float playerGravity {9.8f};
    bool playerIsAnimated {true};
    float playerPositionX {0.0f};
    float playerPositionY {0.0f};
    float playerColliderWidth {16.0f};
    float playerColliderHeight {55.0f};
    float playerColliderOffsetX {8.0f};
    float playerColliderOffsetY {23.0f};


    float multiplier {2.0f};
    playerSpriteScaleX *= multiplier;
    playerSpriteScaleY *= multiplier;
    playerMovementSpeed *= multiplier;
    playerPositionX = 300.0f;
    playerPositionY = 300.0f;
    playerGravity *= multiplier;


    this->playerActorIdleAnimationRenderer.init("src/assets/sprites/characters/main_character/spr_main_char_idle.png", playerSpriteSize, 5);
    this->playerActorMovingAnimationRenderer.init("src/assets/sprites/characters/main_character/spr_main_char_running.png", playerSpriteSize, 4);

    playerActor.init(playerMovementSpeed, playerLayer, playerHasGravity, playerGravity, playerIsAnimated, playerPositionX, playerPositionY, playerColliderWidth, playerColliderHeight, playerSpriteScaleX, playerSpriteScaleY, playerSpriteSize, playerColliderOffsetX, playerColliderOffsetY);
    //playerActor.init(2.5f, 0, false, 9.8f, true, 0.0f, 0.0f, 16.0f, 55.0f, 2.0f, 2.0f, playerSpriteSize);

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