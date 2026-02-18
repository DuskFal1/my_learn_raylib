#include "ui.h"
#include "config.h"

// Присваеваем значения структуре Score
Score CreateGameScore(float size, Color color){
        Score score = {
            .position = {20, 10},
            .count = 0,
            .size = size,
            .color = color
        };        
    return score;      
}

Score InitScore(void){
    Score score = {0};
    score = CreateGameScore(
        20,                                                             // Размер
        WHITE
    );

    return score;
}

// Рисуем очки
void DrawScore(const Score* score){
    DrawText(TextFormat("Score: %d", score->count), score->position.x, score->position.y, 20, score->color);    
}

// Обновляем очки
void UpdateScore(Score* score){
if (IsKeyPressed(KEY_SPACE))
    {
        score->count++;
    } 
}

// Тесты
void TestGame(void){
    //FPS
    DrawText(TextFormat("FPS: %d", GetFPS()), SCREEN_WIDTH - 95, 10, 20, WHITE);
}