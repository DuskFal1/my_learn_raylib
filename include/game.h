#ifndef GAME_H
#define GAME_H

#include <raylib.h>

// Константы игры
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60
#define TREANGLE_RADIUS 20

// Структура игрока 
typedef struct {
    Vector2 position;    // Позиция на экране
    float size;          // Размер треугольника
    float angle;
    Color color;         // Цвет
} Player;

Player CreatePlayer(Vector2 startPosition, float size, Color color);
void gameScore();
void DrawPlayer(Player player);
#endif