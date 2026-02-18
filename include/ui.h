#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "player.h"
#include "enemy.h"

typedef struct {
    Vector2 position;
    float size;
    int count;
    Color color;
} Score;

typedef struct {
    Score score;
} UI;

Score CreateGameScore(float size, Color color);

Score InitScore(void);

void DrawUI(const UI* ui);
void DrawGame(void);
void DrawScore(const Score* score);
void UpdateScore(Score* score);
void TestGame();

#endif