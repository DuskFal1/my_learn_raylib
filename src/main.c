#include "game.h"
#include "raylib.h"

int main(void) {
    SetTraceLogLevel(LOG_INFO);  // или LOG_DEBUG, LOG_WARNING, LOG_ERROR
    // Инициализация окна
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My First Game!");
    SetTargetFPS(FPS);

    GameState game = InitGame();

    // Главный игровой цикл
    while (!WindowShouldClose()) {
        float delta_time = GetFrameTime();              
            UpdateGame(&game, delta_time);
        // Отрисовка
        BeginDrawing();
            RenderGame(&game);
            TestGame(&game.player, &game.bullets);
        EndDrawing();
    }
    
    // Закрытие окна
    CloseWindow();
    
    return 0;
}