#include <ui.h>

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
    ClearBackground(BLACK);                                         // Заливаем фон черным
    DrawRectangle(0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, 20, RED);    // Красная заливка снизу
}

//Рисуем очки
void GameScore(Score *score){
    DrawText(TextFormat("Score: %d", score->count), score->position.x, score->position.y, 20, score->color);
    if (IsKeyPressed(KEY_SPACE))
    {
        score->count++;
    }  
}