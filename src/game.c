#include "game.h"
#include "player.h"
#include "ui.h"

GameState InitGame(void){
    GameState game = {0};
    // Создаем игрока
    game.player = CreatePlayer(
        (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7},   // Начальная позиция
        30.0f,                                          // Размер
        BLUE                                            // Цвет
    );

    // Создаем пулю
    game.bullets = CreateBullets(
        (Vector2){game.player.position.x, game.player.position.y - 50}, // Начальная позиция
        2,                                                              // Ширина
        4,                                                              // Высота
        300,                                                            // Скорость
        GREEN                                                           // Цвет
    );
    
    // Создаем счет
    game.score = CreateGameScore(
        20,                                                             // Размер
        WHITE                                                           // Цвет
    );

    return game;
}

// Тут будет немного функционала и логики
void Game(Player *player, Score *score, Bullets* bullets){
    // Сброс
    if(IsKeyPressed(KEY_R)){
        player->position = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7};
        bullets->isActive = false;
        score->count = 0;
    }
}

// Рисуем экран
void RenderGame(const GameState* game){
    DrawGame();                                     // Рисуем игровой экран
    DrawPlayer(game->player);                       // Рисуем игрока
    DrawBullets(game->bullets);                     // Рисуем пулю
    DrawScore(&game->score);                        // Рисуем счет  
}

// Обновляем экран
void UpdateGame(GameState* game, float delta_time){
    Game(&game->player, &game->score, &game->bullets);  // Логика
    UpdatePlayer(&game->player);                        // Изменение позиции игрока
    UpdateBullets(&game->bullets, &game->player);       // Изменение позиции пули
    UpdateScore(&game->score);                          // Обновляем счет
}

// Тесты
void TestGame(const Player* player,const Bullets* bullets){
    //FPS
    DrawText(TextFormat("FPS: %d", GetFPS()), SCREEN_WIDTH -200, 10, 20, WHITE);
    // Позиция игрока
    DrawText(TextFormat("Position X: %d", (int)player->position.x), SCREEN_WIDTH -200, 30, 20, WHITE);
    DrawText(TextFormat("Position Y: %d", (int)player->position.y), SCREEN_WIDTH -200, 50, 20, WHITE);
    // Позиция пули
    DrawText(TextFormat("B_Position X %d", (int)bullets->position.x),SCREEN_WIDTH -200, 70, 20, WHITE);
    DrawText(TextFormat("B_Position Y %d", (int)bullets->position.y),SCREEN_WIDTH -200, 90, 20, WHITE);
}
