#include "game.h"
#include <raylib.h>

int main(void) {
    // Инициализация окна
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My First Game!");
    SetTargetFPS(FPS);

    // Создаем игрока
    Player player = CreatePlayer(
        (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7},   // Начальная позиция
        30.0f,                                          // Размер
        BLUE                                            // Цвет
    );

    //Создаем пулю
    Bullets bullets = CreateBullets(
        (Vector2){player.position.x, player.position.y - 50},
        2,
        4,
        300,
        GREEN
    );

    //Создаем счет
    Score score = CreateGameScore(
        (Vector2){20, 20},
        20,
        WHITE
    );

    // Главный игровой цикл
    while (!WindowShouldClose()) {
        UpdatePlayer(&player);                  // Изменение позиции игрока
        UpdateBullets(&bullets, &player);       // Изменение позиции пули
        // Отрисовка
        BeginDrawing();
            DrawGame();                         // Рисуем игровой экран
            DrawPlayer(player);                 // Рисуем игрока
            DrawBullets(&bullets, &player);     // Рисуем пулю
            GameScore(&score);                  // Рисуем счет
            Game(&player, &score, &bullets);              // Логика
            GameTestPositionBullets(bullets);   // Проверка позиции пули
            GameTestPosition(player);           // Проверка позиции для отладки
        EndDrawing();
    }
    
    // Закрытие окна
    CloseWindow();
    
    return 0;
}