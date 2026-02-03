#include "bullets.h"
#include "player.h"
#include "game.h"
#include "player.h"

Bullets CreateBullets(Vector2 position, int sizeX, int sizeY, float speed, Color color){
    Bullets bullets = {
        .position = position,
        .sizeX = sizeX,
        .sizeY = sizeY,
        .speed = speed,
        .isActive = false,
        .color = color
    };
    return bullets;
}

//Рисуем пулю с прицелом
void DrawBullets(Bullets *bullets, Player *player){
    //Отрисовываем если не активна
    if (!bullets->isActive) {
        bullets->position.x = player->position.x - bullets->sizeX / 2;
        bullets->position.y = player->position.y - 33;
        DrawRectangle(bullets->position.x, bullets->position.y, bullets->sizeX, bullets->sizeY, bullets->color);
    }
    
    // Отрисовываем только если пуля активна
    if (bullets->isActive) {
        DrawRectangle(bullets->position.x, bullets->position.y, bullets->sizeX, bullets->sizeY, bullets->color);
    }     
}

void DrawUpdateBullets(Bullets *bullets, Player *player){
if (IsKeyPressed(KEY_SPACE))
    {   
        bullets->isActive = true;                       
    }
    if (bullets->isActive)
        {
            bullets->position.y -= bullets->speed * GetFrameTime();  
        } 
    if (bullets->position.y + bullets->sizeY <= 0)
    {
        bullets->position = player->position;
        bullets->isActive = false;
    }
}