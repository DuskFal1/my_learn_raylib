#include "game.h"

int main(void) {
    // Инициализация окна
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Моя первая игра - Прыгающий шарик!");
    SetTargetFPS(FPS);
    
    // Инициализация состояния игры
    GameState game;
    init_game(&game);
    
    // Главный игровой цикл
    while (!WindowShouldClose()) {
        // Обработка ввода
        handle_input(&game);
        
        // Обновление игры
        update_game(&game);
        
        // Отрисовка
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_game(&game);
        EndDrawing();
    }
    
    // Закрытие окна
    CloseWindow();
    
    return 0;
}