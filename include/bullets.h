#ifndef BULLETS_H
#define BULLETS_H

#include <raylib.h>
#include <player.h>

typedef struct {
    Vector2 position;
    Color color;
    int sizeX, sizeY;
    float speed;
    bool isActive;
}Bullets;

Bullets CreateBullets(Vector2 position, int sizeX, int sizeY, float speed, Color color);
void DrawBullets(Bullets *bullets, Player *player);
void UpdateBullets(Bullets *bullets, Player *player);

#endif