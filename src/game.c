#include "game.h"
#include <stdio.h>
#include <math.h>

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

// Присваеваем значения структуре Score
Score CreateGameScore(Vector2 scorePosition, float size, Color color){
        Score score = {
            .position = scorePosition,
            .count = 0,
            .size = size,
            .color = color
        };
    return score;      
}

//Рисуем игровые текстуры
void DrawGame(void){
    DrawRectangle(0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, 20, RED);
}

//Тут будет немного функционала и логики
void Game(Player *player, Score *score){
    Vector2 startPosition = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7};
    if(IsKeyPressed(KEY_R)){
        player->position = startPosition;
        score->count = 0;
    }
}

//Рисуем очки
void GameScore(Score *score){
    DrawText(TextFormat("Score: %d", score->count), score->position.x, score->position.y, 20, score->color);
    if (IsKeyPressed(KEY_SPACE))
    {
        score->count++;
    }  
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
void UpdatePlayer(Player *player){
    //Вправо
    if (IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT))
    {
        player->position.x += 5;
        if (player->position.x >= SCREEN_WIDTH - 20)
        {
            player->position.x = SCREEN_WIDTH - 20;
        }                  
    }
    //Влево
    if (IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT))
    {
        player->position.x -= 5;
        if (player->position.x <= 20)
        {
            player->position.x = 20;
        } 
    }
    //Вверх
    if (IsKeyPressed(KEY_UP) || IsKeyDown(KEY_UP))
    {
        player->position.y -= 5;
        if (player->position.y <= 80)
        {
            player->position.y = 80;
        }              
    }
    //Вниз
    if (IsKeyPressed(KEY_DOWN) || IsKeyDown(KEY_DOWN))
    {
        player->position.y += 5;
        if (player->position.y >= SCREEN_HEIGHT - 45)
        {
            player->position.y = SCREEN_HEIGHT - 45;
        }
    }  
}

void GameTestPosition(Player player){
    DrawText(TextFormat("Position X: %d", (int)player.position.x), SCREEN_WIDTH -200, 10, 20, WHITE);
    DrawText(TextFormat("Position Y: %d", (int)player.position.y), SCREEN_WIDTH -200, 30, 20, WHITE);
}
