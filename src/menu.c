#include "menu.h"
#include "game.h"

StartMenu CreateStartMenu(void) {
    StartMenu menu = {0};
    menu.selection = 0;
    return menu;
}

void DrawStartMenu(const StartMenu* menu){
    ClearBackground((Color){0, 0, 0 , 255});
    if (menu->selection == 0) {
        DrawCircle(SCREEN_WIDTH/2 - 65, 280, 10, WHITE);
        //DrawRectangleLines(SCREEN_WIDTH/2 - 150, 250, 300, 60, WHITE);
        DrawText("Play", 
                 SCREEN_WIDTH/2 - MeasureText("Play", 40)/2,
                 260, 40, WHITE);
    } else {
        DrawText("Play", 
             SCREEN_WIDTH/2 - MeasureText("Play", 40)/2,
             260, 40, GRAY);
    }

    if (menu->selection == 1) {
        DrawCircle(SCREEN_WIDTH/2 - 65, 360, 10, WHITE);
        DrawText("Exit", 
                 SCREEN_WIDTH/2 - MeasureText("Exit", 40)/2,
                 340, 40, WHITE);
    } else {
        DrawText("Exit", 
                 SCREEN_WIDTH/2 - MeasureText("Exit", 40)/2,
                 340, 40, GRAY);
    }
}

MenuAction UpdateStartMenu(StartMenu* menu) { 
    TraceLog(LOG_DEBUG, "Текущий выбор: %d", menu->selection); 
    // Навигация стрелками
    if (IsKeyPressed(KEY_DOWN)) {
        menu->selection++;  // 0 ↔ 1
        if (menu->selection > 1)
        {
            menu->selection = 0;
        }
        TraceLog(LOG_INFO, "Selection changed to %d (DOWN)", menu->selection);
    }

    if (IsKeyPressed(KEY_UP)) {
        menu->selection--;  // 0 ↔ 1
        if (menu->selection < 0)
        {
            menu->selection = 1;
        }
    }
    
    // Выбор Enter
    if (IsKeyPressed(KEY_ENTER)) {
        if (menu->selection == 0) {
            return MENU_ACTION_START_GAME;
        } else {
            return MENU_ACTION_EXIT;
        }
    }
    
    // Выход по Escape
    if (IsKeyPressed(KEY_ESCAPE)) {
        return MENU_ACTION_EXIT;
    }
    
    return MENU_ACTION_NONE;
}