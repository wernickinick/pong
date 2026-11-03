#include "raylib.h"

class Ball{

private:
    float x,y;;
    float speedX, speedY;
    float radius;

public:
    Ball(float startX, float startY,float sX, float sY, float r);
    void Update(int& leftScore, int& rightScore);
    void Draw() const;
    void Reset();
    Vector2 GetPosition() const;
    float GetRadius() const;
    void BounceX();
};
