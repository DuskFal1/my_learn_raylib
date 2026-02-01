#include <game.h>
#include <player.h>

//Тут будет немного функционала и логики
void Game(Player *player, Score *score){
    Vector2 startPosition = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT/8*7};
    if(IsKeyPressed(KEY_R)){
        player->position = startPosition;
        score->count = 0;
    }
}

void GameTestPosition(Player player){
    DrawText(TextFormat("Position X: %d", (int)player.position.x), SCREEN_WIDTH -200, 10, 20, WHITE);
    DrawText(TextFormat("Position Y: %d", (int)player.position.y), SCREEN_WIDTH -200, 30, 20, WHITE);
}
