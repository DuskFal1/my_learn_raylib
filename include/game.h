#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <player.h>
#include <ui.h>

// Константы игры
#define FPS 60
#define TREANGLE_RADIUS 20




void DrawGame(void);

void GameTestPosition(Player player);

void Game(Player *player, Score *score);
#endif