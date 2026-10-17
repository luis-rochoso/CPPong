// CPPong Project
#include "raylib.h"

// CONSTANTS
const int SCREEN_W       = 960; 
const int SCREEN_H       = 540;
const int FPS_TARGET     = 60;
const float BALL_SIZE    = 20;

// VARIABLES
Vector2 ballPos {SCREEN_W / 2, SCREEN_H / 2};
float BALL_SPEED_X = 320;
float BALL_SPEED_Y = 240;

void Update() {

    if (ballPos.x < 0 || ballPos.x + BALL_SIZE > SCREEN_W) {
        BALL_SPEED_X = -BALL_SPEED_X;
    }
    if (ballPos.y < 0 || ballPos.y + BALL_SIZE > SCREEN_H) {
        BALL_SPEED_Y = -BALL_SPEED_Y;
    }

    ballPos.x += BALL_SPEED_X / FPS_TARGET;
    ballPos.y += BALL_SPEED_Y / FPS_TARGET;
}

void Render() {
    BeginDrawing();

        ClearBackground(BLACK);
        DrawRectangle(ballPos.x, ballPos.y, BALL_SIZE, BALL_SIZE, WHITE);

    EndDrawing();
}



int main() {

    // Initialization
    InitWindow(SCREEN_W, SCREEN_H, "CPPong");
    SetTargetFPS(FPS_TARGET);

    while(!WindowShouldClose()) {
        Update();
        Render();
    }

    CloseWindow();

}