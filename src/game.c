#include <game.h>
#include <player.h>

// Тут будет немного функционала и логики
void Game(Player *player, Score *score, Bullets* bullets){
    Vector2 startPosition = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7};
    // Сброс
    if(IsKeyPressed(KEY_R)){
        player->position = startPosition;
        bullets->isActive = false;
        score->count = 0;
    }
}

// Тест позиции игрока
void GameTestPosition(Player player){
    DrawText(TextFormat("Position X: %d", (int)player.position.x), SCREEN_WIDTH -200, 10, 20, WHITE);
    DrawText(TextFormat("Position Y: %d", (int)player.position.y), SCREEN_WIDTH -200, 30, 20, WHITE);
}

// Тест позиции пули
void GameTestPositionBullets(Bullets bullets){
    DrawText(TextFormat("B_Position X %d", (int)bullets.position.x),SCREEN_WIDTH -200, 50, 20, WHITE);
    DrawText(TextFormat("B_Position Y %d", (int)bullets.position.y),SCREEN_WIDTH -200, 70, 20, WHITE);
}
