#include "ui.h"

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

// Рисуем игровые текстуры
void DrawGame(void){
    ClearBackground(BLACK);                                         // Заливаем фон черным
    DrawRectangle(0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, 20, RED);    // Красная заливка снизу
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
void TestGame(){
    //FPS
    DrawText(TextFormat("FPS: %d", GetFPS()), SCREEN_WIDTH - 95, 10, 20, WHITE);
}