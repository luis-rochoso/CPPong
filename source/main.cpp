// CPPong Project
#include "raylib.h"

// CONSTANTS
const int SCREEN_W   = 960; 
const int SCREEN_H   = 540;
const int FPS_TARGET = 60;
const int BALL_SIZE  = 20;
const int RACKET_W   = BALL_SIZE;
const int RACKET_H   = BALL_SIZE * 5;

// VARIABLES
Vector2 ballPos       = {SCREEN_W / 2, SCREEN_H / 2};
Vector2 leftRacketPos = {SCREEN_W * 0.05 - RACKET_W, 0};
Vector2 riteRacketPos = {SCREEN_W * 0.95, 0};
float BALL_SPEED_X    = 320;
float BALL_SPEED_Y    = 240;

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

        DrawRectangle(leftRacketPos.x, leftRacketPos.y, RACKET_W, RACKET_H, WHITE);
        DrawRectangle(riteRacketPos.x, riteRacketPos.y, RACKET_W, RACKET_H, WHITE);

        DrawLineDashed({SCREEN_W/2 - RACKET_W, 0}, {SCREEN_W/2 - RACKET_W, SCREEN_H},
                       RACKET_H/5, RACKET_H/5, WHITE);

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

    // De-initialization
    CloseWindow();

}