#ifndef UI_H
#define UI_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    float size;
    int count;
    Color color;
} Score;

Score CreateGameScore(float size, Color color);

Score InitScore(void);

void DrawGame(void);
void DrawScore(const Score* score);
void UpdateScore(Score* score);
void TestGame();

#endif