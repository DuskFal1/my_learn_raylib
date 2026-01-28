#include "game.h"
#include <stdio.h>
#include <math.h>

void gameScore(){
    DrawText("Score: ", 10, 10, 20, WHITE);    
}

Player CreatePlayer(Vector2 startPosition, float size, Color color) {
        Player player = {
            .position = startPosition,
            .angle = -1.5708f,       // Смотрит вправо
            .size = size,
            .color = color
        };
    return player;
    }

// Отрисовка игрока на экране
void DrawPlayer(Player player) {
    // Вычисляем три вершины треугольника
    Vector2 points[3];
    
    // Вершина 1: Нос (12 часов)
    points[0].x = player.position.x + cosf(player.angle) * player.size;
    points[0].y = player.position.y + sinf(player.angle) * player.size;
    
    // Вершина 2: Правое крыло (4 часа) 
    // Угол -2.5 радиана ≈ -143° от носа
    points[1].x = player.position.x + cosf(player.angle - 2.5f) * player.size;
    points[1].y = player.position.y + sinf(player.angle - 2.5f) * player.size;
    
    // Вершина 3: Левое крыло (8 часов)
    // Угол +2.5 радиана ≈ +143° от носа
    points[2].x = player.position.x + cosf(player.angle + 2.5f) * player.size;
    points[2].y = player.position.y + sinf(player.angle + 2.5f) * player.size;
    
    // Рисуем залитый треугольник
    DrawTriangle(points[0], points[1], points[2], player.color);
    
    // Рисуем контур
    DrawTriangleLines(points[0], points[1], points[2], RED);
}
