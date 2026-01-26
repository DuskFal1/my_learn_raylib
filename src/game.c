#include "game.h"
#include <stdio.h>

void init_game(GameState* state) {
    // Инициализация шарика
    state->ball.position = (Vector2){SCREEN_WIDTH/2, GROUND_Y - BALL_RADIUS};
    state->ball.velocity = (Vector2){0, 0};
    state->ball.color = MAROON;
    state->ball.is_on_ground = true;
    
    // Инициализация счета
    state->score = 0;
    state->game_over = false;
}

void handle_input(GameState* state) {
    if (state->game_over) return;
    
    // Прыжок при нажатии пробела
    if (IsKeyPressed(KEY_SPACE) && state->ball.is_on_ground) {
        state->ball.velocity.y = JUMP_FORCE;
        state->ball.is_on_ground = false;
        state->score += 10;
    }
    
    // Движение влево/вправо
    if (IsKeyDown(KEY_RIGHT)) {
        state->ball.position.x += 5;
        if (state->ball.position.x > SCREEN_WIDTH - BALL_RADIUS) {
            state->ball.position.x = SCREEN_WIDTH - BALL_RADIUS;
        }
    }
    if (IsKeyDown(KEY_LEFT)) {
        state->ball.position.x -= 5;
        if (state->ball.position.x < BALL_RADIUS) {
            state->ball.position.x = BALL_RADIUS;
        }
    }
    
    // Рестарт игры
    if (IsKeyPressed(KEY_R)) {
        init_game(state);
    }
}

void update_game(GameState* state) {
    if (state->game_over) return;
    
    // Физика шарика
    state->ball.velocity.y += GRAVITY;
    state->ball.position.y += state->ball.velocity.y;
    
    // Проверка земли
    if (state->ball.position.y >= GROUND_Y - BALL_RADIUS) {
        state->ball.position.y = GROUND_Y - BALL_RADIUS;
        state->ball.velocity.y = 0;
        state->ball.is_on_ground = true;
    }
    
    // Проверка проигрыша (упал в яму)
    if (state->ball.position.y > SCREEN_HEIGHT) {
        state->game_over = true;
    }
    
    // Генерация препятствий (позже добавим)
}

void draw_game(GameState* state) {
    // Отрисовка земли
    DrawRectangle(0, GROUND_Y, SCREEN_WIDTH, SCREEN_HEIGHT - GROUND_Y, GREEN);
    
    // Отрисовка шарика
    DrawCircleV(state->ball.position, BALL_RADIUS, state->ball.color);
    DrawCircleLines(state->ball.position.x, state->ball.position.y, BALL_RADIUS, DARKGRAY);
    
    // Отрисовка счета
    DrawText(TextFormat("Score: %d", state->score), 10, 10, 30, DARKGRAY);
    
    // Управление
    DrawText("Управление: СТРЕЛКИ - движение, ПРОБЕЛ - прыжок, R - рестарт", 10, SCREEN_HEIGHT - 30, 20, GRAY);
    
    // Отрисовка состояния игры
    if (!state->ball.is_on_ground) {
        DrawText("В ВОЗДУХЕ!", SCREEN_WIDTH/2 - 60, 50, 30, BLUE);
    }
    
    if (state->game_over) {
        DrawText("ИГРА ОКОНЧЕНА!", SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 - 20, 40, RED);
        DrawText("Нажми R для рестарта", SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 + 30, 30, DARKGRAY);
    }
}