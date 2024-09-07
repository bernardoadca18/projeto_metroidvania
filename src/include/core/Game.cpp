#include "raylib.h"
#include "Game.h"

// Construtor
Game::Game(Game::GameScreen screen, const char* title, int screenWidth, int screenHeight, int targetFPS)
{
    this->screen = screen;
    this->title = title;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->targetFPS = targetFPS;
    this->framesCounter = 0;
    this->gamePaused = false;
}

// Detruidor
Game::~Game()
{


    CloseWindow();
}

// Funções
void Game::init()
{
    // Initialization
    InitWindow(this->getScreenWidth(), this->getScreenHeight(), this->getTitle());

    this->setScreen(Game::GameScreen::LOGO);
    this->setFramesCounter(0);
    this->setGamePaused(false);

    SetTargetFPS(this->getTargetFPS());

    // Actors
    this->actorHandler.actorInitHandler();
}

void Game::gameLoop()
{
    while (!WindowShouldClose())
    {
        this->updateGame();
        this->updateDraw();
    }
}

void Game::updateGame()
{
    this->setFramesCounter(this->getFramesCounter() + 1);

    this->actorHandler.actorUpdateHandler();
}

void Game::updateDraw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    this->actorHandler.actorDrawHandler();

    EndDrawing();
}

// Getters
Game::GameScreen Game::getScreen() const
{
    return this->screen;
}

const char* Game::getTitle() const
{
    return this->title;
}

int Game::getScreenWidth() const
{
    return this->screenWidth;
}

int Game::getScreenHeight() const
{
    return this->screenHeight;
}

int Game::getTargetFPS() const
{
    return this->targetFPS;
}

int Game::getFramesCounter() const
{
    return this->framesCounter;
}

bool Game::getGamePaused() const
{
    return this->gamePaused;
}


// Setters

void Game::setScreen(Game::GameScreen screen)
{
    this->screen = screen;
}

void Game::setTitle(const char* title)
{
    this->title = title;
}

void Game::setScreenWidth(int screenWidth)
{
    this->screenWidth = screenWidth;
}

void Game::setScreenHeight(int screenHeight)
{
    this->screenHeight = screenHeight;
}

void Game::setTargetFPS(int targetFPS)
{
    this->targetFPS = targetFPS;
}

void Game::setFramesCounter(int framesCounter)
{
    this->framesCounter = framesCounter;
}

void Game::setGamePaused(bool gamePaused)
{
    this->gamePaused = gamePaused;
}