#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"
#include "bullets.h"
#include "ui.h"

typedef struct {
    Player player;
    Bullets bullets;
    Score score;
    bool game_over;
    int level;
} GameState;

// Константы игры
#define FPS 60

GameState InitGame(void);

void RenderGame(const GameState* game);
void UpdateGame(GameState* game, float delta_time);
void TestGame(const Player* player, const Bullets* bullets);
void Game(Player* player, Score* score, Bullets* bullets);
#endif