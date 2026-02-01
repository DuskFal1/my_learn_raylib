#include <bullets.h>
//#include <player.h>
#include <game.h>

Bullets CreateBullets(Vector2 position, int sizeX, int sizeY, int speed, Color color){
    Bullets bullets = {
        .position = position,
        .sizeX = sizeX,
        .sizeY = sizeY,
        .speed = speed,
        .color = color
    };
    return bullets;
}

void DrawBullets(Bullets *bullets){

           DrawRectangle(bullets->position.x, bullets->position.y,bullets->sizeX,bullets->sizeY,bullets->color);

}