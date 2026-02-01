#include "game.h"
#include <stdio.h>
#include <math.h>
#include <player.h>



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



void GameTestPosition(Player player){
    DrawText(TextFormat("Position X: %d", (int)player.position.x), SCREEN_WIDTH -200, 10, 20, WHITE);
    DrawText(TextFormat("Position Y: %d", (int)player.position.y), SCREEN_WIDTH -200, 30, 20, WHITE);
}
