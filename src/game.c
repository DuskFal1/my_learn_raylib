#include "game.h"
#include "player.h"
#include "ui.h"
#include "string.h"

const Vector2 startPosition = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT*0.875f};

GameState InitGame(void){
    GameState game = {0};
    // Создаем игрока
    game.player = CreatePlayer(
        startPosition,   // Начальная позиция
        30.0f,                                          // Размер
        BLUE                                            // Цвет
    );

    // Создаем пулю
    game.bullets = CreateBullets(
        (Vector2){startPosition.x, startPosition.y - 50},               // Начальная позиция
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

// Рисуем экран
void RenderGame(const GameState* game){
    DrawGame();                                     // Рисуем игровой экран
    DrawPlayer(game->player);                       // Рисуем игрока
    DrawBullets(game->bullets);                     // Рисуем пулю
    DrawScore(&game->score);                        // Рисуем счет

    switch (game->game_state)
    {
    case GAME_STATE_PAUSED:
        DrawPause(game);
        break;
    default:
        break;
    }    
}

// Обновляем экран
void UpdateGame(GameState* game, float delta_time){
    if (IsKeyPressed(KEY_P))
        {
            if (game->game_state == GAME_STATE_PLAYING)
            {
                game->game_state = GAME_STATE_PAUSED;
            } else if (game->game_state == GAME_STATE_PAUSED)
            {
                game->game_state = GAME_STATE_PLAYING;
            }
        }

    switch (game->game_state)
    {
    case GAME_STATE_PLAYING:
        UpdateGamePlayed(game);
        break;
    case GAME_STATE_PAUSED:
        break;
    default:
        break;
    }
}

void UpdateGamePlayed(GameState* game){
    Game(&game->player, &game->score, &game->bullets);  // Логика
    UpdatePlayer(&game->player);                        // Изменение позиции игрока
    UpdateBullets(&game->bullets, &game->player);       // Изменение позиции пули
    UpdateScore(&game->score);                          // Обновляем счет
}

// Обработка паузы
void DrawPause(const GameState* game){
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0,0,0, 128});
    DrawText("PAUSE", SCREEN_WIDTH/2 - 35, SCREEN_HEIGHT/2, 20, WHITE);
}

// Тут будет немного функционала и логики
void Game(Player *player, Score *score, Bullets* bullets){
    // Сброс
    if(IsKeyPressed(KEY_R)){
        player->position = startPosition;
        bullets->isActive = false;
        score->count = 0;
    }
}

// Тесты
void TestGame(const Player* player, const Bullets* bullets){
    //FPS
    DrawText(TextFormat("FPS: %d", GetFPS()), SCREEN_WIDTH -200, 10, 20, WHITE);
    // Позиция игрока
    DrawText(TextFormat("Position X: %d", (int)player->position.x), SCREEN_WIDTH -200, 30, 20, WHITE);
    DrawText(TextFormat("Position Y: %d", (int)player->position.y), SCREEN_WIDTH -200, 50, 20, WHITE);
    // Позиция пули
    DrawText(TextFormat("B_Position X %d", (int)bullets->position.x),SCREEN_WIDTH -200, 70, 20, WHITE);
    DrawText(TextFormat("B_Position Y %d", (int)bullets->position.y),SCREEN_WIDTH -200, 90, 20, WHITE);
}
