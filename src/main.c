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

    //Создаем счет
    Score score = CreateGameScore(
        (Vector2){20, 20},
        20,
        WHITE
    );

    // Главный игровой цикл
    while (!WindowShouldClose()) {
        // Отрисовка
        BeginDrawing();
            ClearBackground(BLACK);         // Заливаем фон черным
            DrawGame();                     // Рисуем игровой экран
            DrawPlayer(player);             // Рисуем игрока
            UpdatePlayer(&player);          // Изменение позиции игрока
            GameTestPosition(player);       // Проверка позиции для отладки
            GameScore(&score);              // Рисуем счет
            Game(&player, &score);
        EndDrawing();
    }
    
    // Закрытие окна
    CloseWindow();
    
    return 0;
}