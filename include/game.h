#ifndef GAME_H
#define GAME_H

#include <raylib.h>

// Константы игры
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60
#define BALL_RADIUS 20
#define GRAVITY 0.5f
#define JUMP_FORCE -12.0f
#define GROUND_Y 500

// Структура шарика
typedef struct {
    Vector2 position;
    Vector2 velocity;
    Color color;
    bool is_on_ground;
} Ball;

// Структура игры
typedef struct {
    Ball ball;
    int score;
    bool game_over;
} GameState;

// Прототипы функций
void init_game(GameState* state);
void update_game(GameState* state);
void draw_game(GameState* state);
void handle_input(GameState* state);

#endif