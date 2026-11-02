#include "raylib.h"

class Paddle {
    private:
        float x, y;
        float width, height;
        float speed;

    public:
         Paddle(float startX, float startY, float w, float h, float s);
         void update(Keyboard keyUp, Keyboard keyDown);
         void Draw() const;
         Recatangle getRect() const;
};

