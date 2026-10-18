// CPPong Project
#include "raylib.h"
#include <array>

// CONSTANTS
const int SCREEN_W   = 960; 
const int SCREEN_H   = 540;
const int FPS_TARGET = 60;
const int BALL_SIZE  = 20;
const int RACKET_W   = BALL_SIZE;
const int RACKET_H   = BALL_SIZE * 5;

// VARIABLES
Vector2 ballPos        = {SCREEN_W / 2, SCREEN_H / 2};
Vector2 leftRacketPos  = {SCREEN_W * 0.05 - RACKET_W, 0};
Vector2 riteRacketPos  = {SCREEN_W * 0.95, 0};
float BALL_SPEED_X     = 320;
float BALL_SPEED_Y     = 240;
float RACKET_SPEED     = 320;
unsigned int leftScore = 0;
unsigned int riteScore = 0;

const char* ToChar(int n) {
    return TextFormat("%i", n);
}

void Update() {

    // Ball movement
    if (ballPos.x < 0 || ballPos.x + BALL_SIZE > SCREEN_W) {
        BALL_SPEED_X = -BALL_SPEED_X;
    }
    if (ballPos.y < 0 || ballPos.y + BALL_SIZE > SCREEN_H) {
        BALL_SPEED_Y = -BALL_SPEED_Y;
    }

    ballPos.x += BALL_SPEED_X / FPS_TARGET;
    ballPos.y += BALL_SPEED_Y / FPS_TARGET;

    // Racket movement
    if (IsKeyDown(KEY_W)) {
        leftRacketPos.y -= RACKET_SPEED / FPS_TARGET;
        if (leftRacketPos.y < 0) leftRacketPos.y = 0;
    }
    if (IsKeyDown(KEY_S)) {
        leftRacketPos.y += RACKET_SPEED / FPS_TARGET;
        if (leftRacketPos.y + RACKET_H > SCREEN_H) leftRacketPos.y = SCREEN_H - RACKET_H;
    }
    if (IsKeyDown(KEY_UP)) {
        riteRacketPos.y -= RACKET_SPEED / FPS_TARGET;
        if (riteRacketPos.y < 0) riteRacketPos.y = 0;
    }
    if (IsKeyDown(KEY_DOWN)) {
        riteRacketPos.y += RACKET_SPEED / FPS_TARGET;
        if (riteRacketPos.y + RACKET_H > SCREEN_H) riteRacketPos.y = SCREEN_H - RACKET_H;
    }
}

void Render() {
    BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangle(ballPos.x, ballPos.y, BALL_SIZE, BALL_SIZE, WHITE);

        DrawRectangle(leftRacketPos.x, leftRacketPos.y, RACKET_W, RACKET_H, WHITE);
        DrawRectangle(riteRacketPos.x, riteRacketPos.y, RACKET_W, RACKET_H, WHITE);

        DrawLineDashed({SCREEN_W/2, 0}, {SCREEN_W/2, SCREEN_H},
                       RACKET_H/5, RACKET_H/5, WHITE);
        
        float leftScoreX = SCREEN_W * 0.45 - MeasureText(ToChar(leftScore), SCREEN_H / 5);
        DrawText(ToChar(leftScore), leftScoreX, SCREEN_H * 0.05, SCREEN_H / 5, WHITE);
        DrawText(ToChar(riteScore), SCREEN_W * 0.55, SCREEN_H * 0.05, SCREEN_H / 5, WHITE);

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