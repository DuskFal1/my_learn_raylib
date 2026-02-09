#ifndef MENU_H
#define MENU_H

#include <raylib.h>

typedef enum {
    MENU_ACTION_NONE,
    MENU_ACTION_START_GAME,
    MENU_ACTION_EXIT
} MenuAction;

typedef struct {
    int selection;      
} StartMenu;

StartMenu CreateStartMenu(void);
MenuAction UpdateStartMenu(StartMenu* menu);
void DrawStartMenu(const StartMenu* menu);

#endif