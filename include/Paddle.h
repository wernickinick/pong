#include "raylib.h"

class Paddle {
    private:
        float x, y;
        float width, height;
        float speed;

    public:
         Paddle(float startX, float startY, float w, float h, float s);
         void Update(KeyboardKey keyUp, KeyboardKey keyDown);
         void Draw() const;
         Rectangle getRect() const;
};

