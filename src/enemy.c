#include "enemy.h"
#include "stdlib.h"
#include "time.h"

Enemy CreateEnemy(Vector2 position, int size, int speed, bool isActive, Color color){
    Enemy enemy = {
        .position = position,
        .size = size,
        .speed = speed,
        .color = color,
        .isActive = isActive
    };
    return enemy;
}

Enemy InitEnemy(void){
    srand(time(NULL));
    Enemy enemy = {0};
    enemy = CreateEnemy(
        (Vector2){rand() % SCREEN_WIDTH, 10},
        5,
        100,
        false,
        RED
    );
    return enemy;
}

void DrawEnemy(const Enemy* enemy, int count){
    for (int i = 0; i < MAX_ENEMIES; i++) { 
        if (enemy[i].isActive){
            DrawCircle(enemy[i].position.x, enemy[i].position.y, 
                      enemy[i].size, enemy[i].color); 
        }         
    }
}

void UpdateEnemy(Enemy* enemy, int* count, float delta_time){
    // Обновляем позиции активных врагов
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemy[i].isActive){
            enemy[i].position.y += enemy[i].speed * delta_time;    
        // Удаляем, если улетели за экран
            if (enemy[i].position.y > SCREEN_HEIGHT + 50) {
                enemy[i].isActive = false;  // ← Важно: деактивируем!
                (*count)--;
            }
        }   
    }
    SpawnEnemy(enemy, &enemy->enemyCount, &enemy->enemySpawnTimer, 1.0f, delta_time);
}

void SpawnEnemy(Enemy* enemies, int* count, float* spawnTimer, float spawnInterval, float delta_time) {
    // Таймер спавна
    *spawnTimer += delta_time;
    if (*spawnTimer >= spawnInterval) {
        *spawnTimer = 0;
        
        // Ищем свободное место
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].isActive) { 
                enemies[i].position.x = GetRandomValue(50, GetScreenWidth() - 50);
                enemies[i].position.y = 10;
                enemies[i].size = 20;
                enemies[i].speed = 100.0f;
                enemies[i].color = RED;
                enemies[i].isActive = true;
                (*count)++;
                break;   
            }
        }
    }
}