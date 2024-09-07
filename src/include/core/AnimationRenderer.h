#ifndef ANIMATIONRENDERER_H
#define ANIMATIONRENDERER_H

#include "raylib.h"

class AnimationRenderer
{
    private:
        const int MAX_FRAME_SPEED = 15;
        const int MIN_FRAME_SPEED = 1;
        
        typedef struct TextureSheet
        {
            Texture2D sprsh_file;
        } TextureSheet;
        
        TextureSheet sprsh_main_char_running;

        Rectangle frameRec;
        
        char* sprsh_main_char_running_path;
        
        int textureWidth;
        int textureHeight;
        int spriteSize;
        int framesCount;
        int currentFrame;
        int framesCounter;
        int framesSpeed;


    public:
        void init(char* sprsh_main_char_running_path, float posX, float posY, int spriteSize, int framesSpeed);

        void update();

        void draw(Vector2 position);

        AnimationRenderer() {};

        ~AnimationRenderer() {};

        // Setters

        void setSprshMainCharRunningPath(char* sprsh_main_char_running_path);
        void setPosition(float posX, float posY);
        void setSpriteSize(int spriteSize);
        void setFramesSpeed();
        void setFramesSpeed(int frameSpeed);
        void setFramesCount();
        void setFramesCount(int fTextureWidth, int fSpriteSize);
        void setCurrentFrame();
        void setCurrentFrame(int currentFrame);
        void setFramesCounter();
        void setFramesCounter(int framesCounter);
        void setFrameRec();
        void reloadTexture();

        // Getters

        char* getSprshMainCharRunningPath();
        Vector2 getPosition();
        int getTextureWidth();
        int getTextureHeight();
        int getSpriteSize();
        int getFramesSpeed();
        int getFramesCount();
        int getCurrentFrame();
        int getFramesCounter();
        Rectangle getFrameRec();
        Texture2D getTexture();
};

#endif