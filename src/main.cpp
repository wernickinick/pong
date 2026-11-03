#include "raylib.h"
#include "Paddle.h"
#include "Ball.h"

int main(){
    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "PONG");
    SetTargetFPS(60);

    Paddle leftPaddle(20,screenHeight / 2 - 60, 20, 120, 7.0f);
    Paddle rightPaddle(screenWidth - 40, screenHeight / 2 - 60, 20, 120, 7.0f);
    Ball ball (screenWidth / 2, screenHeight / 2, 6.0f, 6.0f, 12.0f);

    int leftScore = 0;
    int rightScore = 0;

    while (!WindowShouldClose()){
        leftPaddle.Update(KEY_W, KEY_S);
        rightPaddle.Update(KEY_UP, KEY_DOWN);
        ball.Update(leftScore, rightScore);

        if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), leftPaddle.getRect())){
            ball.BounceX();
        }
        if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), rightPaddle.getRect())){
            ball.BounceX();
        }

        BeginDrawing();
        ClearBackground(BLUE);

        DrawLine(screenWidth/ 2, 0, screenWidth / 2, screenHeight, RAYWHITE);
        
        DrawText(TextFormat("%d", leftScore), screenWidth / 4, 30, 50, WHITE);

        DrawText(TextFormat("%d", rightScore), 3 * screenWidth / 4, 30, 50, WHITE);
    
        leftPaddle.Draw();
        rightPaddle.Draw();
        ball.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
