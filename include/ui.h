#ifndef UI_H
#define UI_H

#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct {
    Vector2 position;
    float size;
    int count;
    Color color;
} Score;


Score CreateGameScore(Vector2 scorePosition, float size, Color color);
void GameScore(Score *score);


#endif