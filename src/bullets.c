#include "bullets.h"
#include "player.h"
#include "config.h"

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

Bullets InitBullets(void){
    Bullets bullets = {0};
        // Создаем пулю
    bullets = CreateBullets(
        (Vector2){PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y - 50},               // Начальная позиция
        2,                                                              // Ширина
        4,                                                              // Высота
        300,                                                            // Скорость
        GREEN                                                           // Цвет
    );
    return bullets;
}

//Рисуем пулю с прицелом
void DrawBullets(const Bullets bullets){   
        DrawRectangle(bullets.position.x, bullets.position.y, bullets.sizeX, bullets.sizeY, bullets.color);       
}

// Обновление позиции пули
void UpdateBullets(Bullets *bullets, Player *player, float delta_time){
    //Отрисовываем если не активна
    if (!bullets->isActive) {
        bullets->position.x = player->position.x - bullets->sizeX / 2 * delta_time;
        bullets->position.y = player->position.y - 33;
        DrawRectangle(bullets->position.x, bullets->position.y, bullets->sizeX, bullets->sizeY, bullets->color);
    }
    // Выстрел
    if (IsKeyPressed(KEY_SPACE))
        {   
            bullets->isActive = true;                       
        }
        if (bullets->isActive)
            {
                bullets->position.y -= bullets->speed * delta_time;  
            } 
        if (bullets->position.y + bullets->sizeY <= 0)
        {
            bullets->position = player->position;
            bullets->isActive = false;
        }
}