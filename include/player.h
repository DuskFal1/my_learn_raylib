#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "enemy.h"

// Структура игрока 
typedef struct {
    Vector2 position;    // Позиция на экране
    float size;          // Размер треугольника
    float angle;         // Наклон
    Color color;         // Цвет
    int health;          // Здоровье игрока
} Player;

Player CreatePlayer(Vector2 startPosition, float size, int health, Color color);
Player InitPlayer(void);

void DrawPlayer(const Player player);
void UpdatePlayer(Player *player, float delta_time);
void DrawHealths(const Player* player);
void UpdateHealths(Player* player, Enemy* enemies);

#endif