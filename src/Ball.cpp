#include "Ball.h"

Ball::Ball(float startX, float startY, float sX, float sY, float r) {
    x = startX;
    y = startY;
    speedX = sX;
    speedY = sY;
    radius = r;

}

void Ball::Update(int& leftScore, int& rightScore){
    x += speedX;
    y += speedY;

    if (y - radius <= 0|| y + radius >= GetScreenHeight()){
        speedY *= -1.0f;
    }
    if(x + radius <= 0) {
        rightScore++;
        Reset();
    }
    if (x - radius >= GetScreenWidth()){
        leftScore++;
        Reset();
    }
}

void Ball::Draw() const {
    DrawCircle((int)x, (int)y, radius,WHITE);
}

void Ball::Reset(){
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    speedX *= -1.0f;
}

Vector2 Ball::GetPosition() const {
    return Vector2 { x, y };
}

float Ball::GetRadius() const {
    return radius;
}

void Ball::BounceX(){
speedX *= -1.0f;
}

