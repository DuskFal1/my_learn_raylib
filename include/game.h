#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"
#include "bullets.h"
#include "ui.h"

typedef enum{
    GAME_STATE_PLAYING,
    GAME_STATE_PAUSED
} GameStateType;

typedef struct {
    GameStateType game_state;
    Player player;
    Bullets bullets;
    Score score;
    bool isPause;
    int level;
} GameState;

// Константы игры
#define FPS 60

GameState InitGame(void);

void RenderGame(const GameState* game);
void UpdateGame(GameState* game, float delta_time);
void UpdateGamePlayed(GameState* game, float delta_time);
void DrawPause(const GameState* game);
void TestGame(const Player* player, const Bullets* bullets);
void Game(Player* player, Score* score, Bullets* bullets);
#endif