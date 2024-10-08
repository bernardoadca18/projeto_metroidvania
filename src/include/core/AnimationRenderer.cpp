#include "AnimationRenderer.h"
#include "raylib.h"

void AnimationRenderer::init(char* sprsh_main_char_running_path, int spriteSize, int framesSpeed)
{
    this->sprsh_main_char_running_path = sprsh_main_char_running_path;
    this->spriteSize = spriteSize;
    this->framesSpeed = framesSpeed;

    if (sprsh_main_char_running_path != nullptr) 
    { 
        this->sprsh_main_char_running.sprsh_file = LoadTexture(this->sprsh_main_char_running_path); 
    }
    
    if (sprsh_main_char_running.sprsh_file.height != 0 && sprsh_main_char_running.sprsh_file.width != 0)
    {
        this->textureWidth = this->sprsh_main_char_running.sprsh_file.width;
        this->textureHeight = this->sprsh_main_char_running.sprsh_file.height;
    }

    this->framesCounter = 0;
    this->currentFrame = 0;
    this->framesCount = this->textureWidth / this->spriteSize;
    this->frameRec = {0.0f, 0.0f, ((float)textureWidth)/framesCount, float(textureHeight)};
}

void AnimationRenderer::update()
{
    this->setFramesCounter(this->framesCounter + 1);

    if (this->framesCounter >= (60 / this->framesSpeed))
    {
        this->setFramesCounter();
        this->setCurrentFrame(this->currentFrame + 1);

        if (this->currentFrame >= this->framesCount)
        {
            this->currentFrame = 0;
        }
        this->frameRec.x = (float)this->currentFrame * this->spriteSize;
    }
}

void AnimationRenderer::draw(Vector2 position, float scaleX, float scaleY, float positionX, float positionY, bool flipX)
{
    Rectangle destRect {positionX, positionY, frameRec.width*scaleX, frameRec.height*scaleY};
    Rectangle invertedXRect {frameRec.x, frameRec.y, frameRec.width*-1.0f, frameRec.height};
    
    if (flipX)
    {
        DrawTexturePro(this->sprsh_main_char_running.sprsh_file,  invertedXRect, destRect, {destRect.width*0.5f, destRect.height*0.5f}, 0, WHITE);
    }
    else
    {
        DrawTexturePro(this->sprsh_main_char_running.sprsh_file,  this->frameRec, destRect, {destRect.width*0.5f, destRect.height*0.5f}, 0, WHITE);
    }
}

// Setters
void AnimationRenderer::setSprshMainCharRunningPath(char* sprsh_main_char_running_path)
{
    this->sprsh_main_char_running_path = sprsh_main_char_running_path;
}

void AnimationRenderer::setSpriteSize(int spriteSize)
{
    this->spriteSize = spriteSize;
}

void AnimationRenderer::setFramesSpeed()
{
    this->framesSpeed = this->MAX_FRAME_SPEED;
}

void AnimationRenderer::setFramesSpeed(int frameSpeed)
{
    this->framesSpeed = frameSpeed;
}

void AnimationRenderer::setFramesCount()
{
    this->framesCount = this->textureWidth / this->spriteSize;
}

void AnimationRenderer::setFramesCount(int fTextureWidth, int fSpriteSize)
{
    this->framesCount = fTextureWidth / fSpriteSize;
}

void AnimationRenderer::setCurrentFrame()
{
    this->currentFrame = 0;
}

void AnimationRenderer::setCurrentFrame(int currentFrame)
{
    this->currentFrame = currentFrame;
}

void AnimationRenderer::setFramesCounter()
{
    this->framesCounter = 0;
}

void AnimationRenderer::setFramesCounter(int framesCounter)
{
    this->framesCounter = framesCounter;
}

void AnimationRenderer::setFrameRec()
{
    this->frameRec = {0.0f, 0.0f, ((float)textureWidth)/framesCount, float(textureHeight)};
}

void AnimationRenderer::setPosition(float posX, float posY)
{
    this->frameRec.x = posX;
    this->frameRec.y = posY;
}

// Getters
char* AnimationRenderer::getSprshMainCharRunningPath()
{
    return this->sprsh_main_char_running_path;
}

int AnimationRenderer::getTextureWidth()
{
    return this->textureWidth;
}

int AnimationRenderer::getTextureHeight()
{
    return this->textureHeight;
}

int AnimationRenderer::getSpriteSize()
{
    return this->spriteSize;
}

int AnimationRenderer::getFramesSpeed()
{
    return this->framesSpeed;
}

int AnimationRenderer::getFramesCount()
{
    return this->framesCount;
}

int AnimationRenderer::getCurrentFrame()
{
    return this->currentFrame;
}

int AnimationRenderer::getFramesCounter()
{
    return this->framesCounter;
}

Rectangle AnimationRenderer::getFrameRec()
{
    return this->frameRec;
}

Texture2D AnimationRenderer::getTexture()
{
    return this->sprsh_main_char_running.sprsh_file;
}

Vector2 AnimationRenderer::getPosition()
{
    return Vector2{this->frameRec.x, this->frameRec.y};
}

// Texture reloader
void AnimationRenderer::reloadTexture()
{
    this->sprsh_main_char_running.sprsh_file = LoadTexture(this->sprsh_main_char_running_path);
}