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
    float angle;         // Наклон
    Color color;         // Цвет
} Player;

typedef struct {
    Vector2 position;
    float size;
    int count;
    Color color;
} Score;

Player CreatePlayer(Vector2 startPosition, float size, Color color);
Score CreateGameScore(Vector2 scorePosition, float size, Color color);

void DrawGame(void);
void GameScore(Score *score);
void GameTestPosition(Player player);
void DrawPlayer(Player player);
void UpdatePlayer(Player *player);
void Game(Player *player, Score *score);
#endif