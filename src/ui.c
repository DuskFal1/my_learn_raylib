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

//Рисуем очки
void GameScore(Score *score){
    DrawText(TextFormat("Score: %d", score->count), score->position.x, score->position.y, 20, score->color);
    if (IsKeyPressed(KEY_SPACE))
    {
        score->count++;
    }  
}