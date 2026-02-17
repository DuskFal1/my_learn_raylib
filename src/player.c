#include "player.h"
#include "math.h"
#include "ui.h"
#include "config.h"

// Присваеваем значения структуре Player
Player CreatePlayer(Vector2 startPosition, float size, Color color) {
    Player player = {
        .position = startPosition,
        .angle = -1.5708f,       // Смотрит вверх
        .size = size,
        .color = color
    };   
    return player;
}

Player InitPlayer(void){
    Player player = {0};
    // Создаем игрока
    player = CreatePlayer(
        PLAYER_START_POSITION,                                  // Начальная позиция
        30.0f,                                          // Размер
        BLUE                                            // Цвет
    );
    return player;
}

// Отрисовка игрока на экране
void DrawPlayer(Player player) {
    // Вычисляем три вершины треугольника
    Vector2 points[3];
    
    // Вершина 1: Нос (12 часов)
    points[0].x = player.position.x + cosf(player.angle) * player.size;
    points[0].y = player.position.y + sinf(player.angle) * player.size;
    
    // Вершина 2: Правое крыло (4 часа) 
    // Угол -2.5 радиана ≈ -143° от носа
    points[1].x = player.position.x + cosf(player.angle - 2.5f) * player.size;
    points[1].y = player.position.y + sinf(player.angle - 2.5f) * player.size;
    
    // Вершина 3: Левое крыло (8 часов)
    // Угол +2.5 радиана ≈ +143° от носа
    points[2].x = player.position.x + cosf(player.angle + 2.5f) * player.size;
    points[2].y = player.position.y + sinf(player.angle + 2.5f) * player.size;
    
    // Рисуем залитый треугольник
    DrawTriangle(points[0], points[1], points[2], player.color);
    
    // Рисуем контур
    DrawTriangleLines(points[0], points[1], points[2], RED);
}

//Перемещение игрока
void UpdatePlayer(Player *player, float delta_time){
    //Вправо
    if (IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT))
    {
        player->position.x += 300 * delta_time;
        if (player->position.x >= SCREEN_WIDTH - 20)
        {
            player->position.x = SCREEN_WIDTH - 20;
        }                  
    }
    //Влево
    if (IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT))
    {
        player->position.x -= 300 * delta_time;
        if (player->position.x <= 20)
        {
            player->position.x = 20;
        } 
    }
    //Вверх
    if (IsKeyPressed(KEY_UP) || IsKeyDown(KEY_UP))
    {
        player->position.y -= 300 * delta_time;
        if (player->position.y <= 80)
        {
            player->position.y = 80;
        }              
    }
    //Вниз
    if (IsKeyPressed(KEY_DOWN) || IsKeyDown(KEY_DOWN))
    {
        player->position.y += 300 * delta_time;
        if (player->position.y >= SCREEN_HEIGHT - 45)
        {
            player->position.y = SCREEN_HEIGHT - 45;
        }
    }  
}