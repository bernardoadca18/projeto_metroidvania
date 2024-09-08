#include "include/core/Game.h"

const int BASE_SCREEN_WIDTH =  1280;//640;
const int BASE_SCREEN_HEIGHT = 720;//360;

int main(int argc, char const *argv[])
{
    Game game(Game::GameScreen::LOGO, "Game", BASE_SCREEN_WIDTH, BASE_SCREEN_HEIGHT, 60);

    game.init();
    game.gameLoop();

    return 0;
}
