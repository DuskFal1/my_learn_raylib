#include "enemy.h"
#include "stdlib.h"
#include "time.h"

Enemy CreateEnemy(Vector2 position, EnemyType type){
    Enemy enemy = {0};
    enemy.position = position;
    enemy.isActive = true;
    enemy.type = type;

    switch (type){
        case ENEMY_TYPE_BASIC:
            enemy.size = 20;
            enemy.speed = 100.0f;
            enemy.color = RED;
            break;
        case ENEMY_TYPE_FAST:
            enemy.size = 20;
            enemy.speed = 200.0f;
            enemy.color = GREEN;
            break;
        case ENEMY_TYPE_TANK:
            enemy.size = 20;
            enemy.speed = 50.0f;
            enemy.color = BLUE;
            break;
    }

    return enemy;
}

void InitEnemies(Enemy* enemies){
    for (int i = 0; i < MAX_ENEMIES; i++){
        enemies[i].isActive = false;
    }   
}

void DrawEnemy(const Enemy* enemies){
    for (int i = 0; i < MAX_ENEMIES; i++) { 
        if (enemies[i].isActive){
            DrawCircle(enemies[i].position.x, enemies[i].position.y, 
                      enemies[i].size, enemies[i].color); 
        }         
    }
}

void UpdateEnemy(Enemy* enemies, int* count, float delta_time){
    // Обновляем позиции активных врагов
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].isActive){
            enemies[i].position.y += enemies[i].speed * delta_time;    
        // Удаляем, если улетели за экран
            if (enemies[i].position.y > SCREEN_HEIGHT - 50) {
                enemies[i].isActive = false;  // ← Важно: деактивируем!
                (*count)--;
            }
        }   
    }
}

// Получение случайного типа врага
EnemyType GetRandomEnemyType(void) {
    int r = rand() % 100;
    if (r < 60) return ENEMY_TYPE_BASIC;      // 60% - обычные
    if (r < 85) return ENEMY_TYPE_FAST;       // 25% - быстрые
    return ENEMY_TYPE_TANK;                    // 15% - танки
}

void SpawnEnemy(Enemy* enemies, int* count, float* spawnTimer, float spawnInterval, float delta_time) {
    // Таймер спавна
    *spawnTimer += delta_time;
    if (*spawnTimer >= spawnInterval) {
        *spawnTimer = 0;
        
        // Ищем свободное место
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].isActive) { 
                // Случайная позиция X
                float x = GetRandomValue(50, GetScreenWidth() + 50);
                
                // Случайный тип врага
                EnemyType type = GetRandomEnemyType();
                
                // Создаем врага
                enemies[i] = CreateEnemy((Vector2){x, 10}, type);
                (*count)++;
                break;
            }
        }
    }
}