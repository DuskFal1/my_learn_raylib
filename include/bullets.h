#ifndef BULLETS_H
#define BULLETS_H

#include <raylib.h>
//#include <player.h>

typedef struct {
    Vector2 position;
    Color color;
    int sizeX;
    int sizeY;
    int speed;
}Bullets;

Bullets CreateBullets(Vector2 position, int sizeX, int sizeY, int speed, Color color);
void DrawBullets(Bullets *bullets);

#endif