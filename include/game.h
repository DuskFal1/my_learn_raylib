#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"
#include "bullets.h"
#include "ui.h"
#include "menu.h"
#include "config.h"

typedef enum{
    GAME_STATE_PLAYING,
    GAME_STATE_START_MENU,
    GAME_STATE_PAUSED,
    GAME_STATE_GAMEOVER
} GameStateType;

typedef struct {
    GameStateType game_state;
    StartMenu menu;
    Player player;
    Bullets bullets;
    Score score;
    int level;    
} GameState;

// Константы игры
#define FPS 60

GameState InitGame(void);



void RenderGame(const GameState* game);
void UpdateGame(GameState* game, float delta_time);
void UpdateGamePlayed(GameState* game, float delta_time);
void DrawPause(const GameState* game);
void UpdatePause(GameState* game);
void DrawGameOver(const GameState* game);
void UpdateGameOver(GameState* game);
void ResetGame(GameState *game);
#endif