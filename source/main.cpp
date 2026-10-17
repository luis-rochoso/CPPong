// CPPong Project
#include "raylib.h"

// CONSTANTS
const int SCREEN_W    = 960; 
const int SCREEN_H    = 540;
const int FPS_TARGET  = 60;
const float BALL_SIZE = 20;

// VARIABLES
Vector2 ballPos {SCREEN_W / 2, SCREEN_H / 2};

void Update() {

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