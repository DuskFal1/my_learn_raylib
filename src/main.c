#include "game.h"
#include <raylib.h>

int main(void) {
    // Инициализация окна
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Моя первая игра - Прыгающий шарик!");
    SetTargetFPS(FPS);

    // 3. Создаем игрока
    Player player = CreatePlayer(
        (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7},   // Начальная позиция
        30.0f,                                          // Размер
        BLUE                                            // Цвет
    );
    
    // Главный игровой цикл
    while (!WindowShouldClose()) {
        // Отрисовка
        BeginDrawing();
            ClearBackground(BLACK);
            // Рисуем игрока
            DrawPlayer(player);
            gameScore();
            
        EndDrawing();
    }
    
    // Закрытие окна
    CloseWindow();
    
    return 0;
}