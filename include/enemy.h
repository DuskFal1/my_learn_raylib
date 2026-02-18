#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "config.h"

#define MAX_ENEMIES 20  // Максимум врагов на экране

typedef enum {
    ENEMY_TYPE_BASIC,
    ENEMY_TYPE_FAST,
    ENEMY_TYPE_TANK
} EnemyType;

typedef struct {
    Vector2 position;
    bool isActive;
    int size;
    int speed;
    Color color;
    EnemyType type;
} Enemy;

Enemy CreateEnemy(Vector2 position, EnemyType type);
void InitEnemies(Enemy* enemies);

void DrawEnemy(const Enemy* enemies);
void UpdateEnemy(Enemy* enemies, int* count, float delta_time);
void SpawnEnemy(Enemy* enemies, int* count, float* spawnTimer, float spawnInterval, float delta_time);

#endif