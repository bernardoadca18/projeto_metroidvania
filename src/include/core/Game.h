#ifndef GAME_H
#define GAME_H

#include "Actor.h"
#include "ActorHandler.h"

class Game
{
    public:
        typedef enum GameScreen
        {
            LOGO,
            TITLE,
            GAMEPLAY,
            ENDING
        } GameScreen;

    private:
        GameScreen screen;
        ActorHandler actorHandler;
        const char* title;
        int screenWidth;
        int screenHeight;
        int targetFPS;
        int framesCounter;
        bool gamePaused;
        bool raylibInitialized;

        void updateGame();
        void updateDraw();

    public:
        Game(GameScreen screen, const char* title, int screenWidth, int screenHeight, int targetFPS);
        ~Game();
        void init();
        void gameLoop();

        // Getters
        GameScreen getScreen() const;
        const char* getTitle() const;
        int getScreenWidth() const;
        int getScreenHeight() const;
        int getTargetFPS() const;
        int getFramesCounter() const;
        bool getGamePaused() const;
        ActorHandler getActorHandler() const ;

        // Setters
        void setScreen(GameScreen screen);
        void setTitle(const char* title);
        void setScreenWidth(int screenWidth);
        void setScreenHeight(int screenHeight);
        void setTargetFPS(int targetFPS);
        void setFramesCounter(int framesCounter);
        void setGamePaused(bool gamePaused);
};


#endif