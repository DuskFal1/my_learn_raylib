#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "config.h"

#define MAX_ENEMIES 20  // Максимум врагов на экране

typedef struct {
    Vector2 position;
    bool isActive;
    int size;
    int speed;
    int count;
    int enemyCount;               
    float enemySpawnTimer; 
    Color color;
} Enemy;

typedef struct {
    Enemy* enemies;
    int count;
    int maxCount;
    float spawnTimer;
    float spawnInterval;
} EnemySystem;


Enemy CreateEnemy(Vector2 position, int size, int speed, bool isActive, Color color);
Enemy InitEnemy(void);

void DrawEnemy(const Enemy* enemy, int count);
void UpdateEnemy(Enemy* enemy, int* count, float delta_time);
void SpawnEnemy(Enemy* enemies, int* count, float* spawnTimer, float spawnInterval, float delta_time);

#endif