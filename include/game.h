#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <player.h>
#include <bullets.h>
#include <ui.h>

// Константы игры
#define FPS 60

void DrawGame(void);
void GameTestPosition(Player player);
void GameTestPositionBullets(Bullets bullets);
void Game(Player *player, Score *score, Bullets* bullets);
#endif