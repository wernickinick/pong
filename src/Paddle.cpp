#include "Paddle.h"

Paddle::Paddle(float startX, float startY, float w, float h, float s) {
    x = startX;
    y = startY;
    width = w;
    height = h;
    speed = s;
}

void Paddle::Update(KeyboardKey keyUp, KeyboardKey keyDown){
    if (IsKeyDown(keyUp)){
        y -= speed;
    }
    if (IsKeyDown(keyDown)){
        y += speed;
    }
    if ( y <= 0 ) {
        y = 0;
    }
    if (y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }
}

void Paddle::Draw() const {
    DrawRectangle((int)x, (int)y, (int)width, (int)height, WHITE);
}

Rectangle Paddle::getRect() const {
    return Rectangle{ x, y, width, height};
}

