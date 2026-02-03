#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

// Структура игрока 
typedef struct {
    Vector2 position;    // Позиция на экране
    float size;          // Размер треугольника
    float angle;         // Наклон
    Color color;         // Цвет
} Player;

Player CreatePlayer(Vector2 startPosition, float size, Color color);
void DrawPlayer(Player player);
void UpdatePlayer(Player *player);

#endif