#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <player.h>

// Константы игры
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60
#define TREANGLE_RADIUS 20



typedef struct {
    Vector2 position;
    float size;
    int count;
    Color color;
} Score;


Score CreateGameScore(Vector2 scorePosition, float size, Color color);

void DrawGame(void);
void GameScore(Score *score);
void GameTestPosition(Player player);

void Game(Player *player, Score *score);
#endif