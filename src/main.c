#include "game.h"
#include "raylib.h"

int main(void) {
    // Инициализация окна
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My First Game!");
    SetTargetFPS(FPS);

    GameState game = InitGame();

    // Главный игровой цикл
    while (!WindowShouldClose()) {
        
        UpdateGame(&game);
        // Отрисовка
        BeginDrawing();
            RenderGame(&game);
            TestGame(game.player, game.bullets);
        EndDrawing();
    }
    
    // Закрытие окна
    CloseWindow();
    
    return 0;
}