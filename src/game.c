#include "game.h"
#include "player.h"
#include "ui.h"
#include "string.h"
#include "menu.h"

const Vector2 startPosition = (Vector2){SCREEN_WIDTH/2, SCREEN_HEIGHT*0.875f};

GameState InitGame(void){
    GameState game = {0};
    game.game_state = GAME_STATE_START_MENU;
    // Создаем игрока
    game.player = CreatePlayer(
        startPosition,                                  // Начальная позиция
        30.0f,                                          // Размер
        BLUE                                            // Цвет
    );

    // Создаем пулю
    game.bullets = CreateBullets(
        (Vector2){startPosition.x, startPosition.y - 50},               // Начальная позиция
        2,                                                              // Ширина
        4,                                                              // Высота
        300,                                                            // Скорость
        GREEN                                                           // Цвет
    );
    
    game.score = InitScore();

    return game;
}

// Рисуем экран
void RenderGame(const GameState* game){
    switch (game->game_state){
        case GAME_STATE_START_MENU:
            DrawStartMenu(&game->menu);
            break;
        case GAME_STATE_PLAYING:
            DrawGame();                                     // Рисуем игровой экран
            DrawPlayer(game->player);                       // Рисуем игрока
            DrawBullets(game->bullets);                     // Рисуем пулю
            DrawScore(&game->score);                        // Рисуем счет
            break;
        case GAME_STATE_PAUSED:
            DrawPause(game);
            break;
        case GAME_STATE_GAMEOVER:
            DrawGameOver(game);
            break;
        default:
            break;
    }    
}

// Обновляем экран
void UpdateGame(GameState* game, float delta_time){
    MenuAction action;

    UpdateGameOver(game);
    UpdatePause(game);
    
    switch (game->game_state){
    case GAME_STATE_PLAYING:
        UpdateGamePlayed(game, delta_time);
        break;
    case GAME_STATE_START_MENU:
        action = UpdateStartMenu(&game->menu);
            switch (action) {
                case MENU_ACTION_START_GAME:
                    // Начать игру - переходим в состояние игры
                    game->game_state = GAME_STATE_PLAYING;
                    // Возможно, нужно сбросить или инициализировать игру здесь
                    break;
                case MENU_ACTION_EXIT:
                    // Выход из игры
                    CloseWindow();
                    break;
                default:
                    break;
            }
        break;
    case GAME_STATE_PAUSED:
        
        break;
    case GAME_STATE_GAMEOVER:            
        ResetGame(game);          
        break;
    default:
        break;
    }   
}

void UpdateGamePlayed(GameState* game, float delta_time){
    UpdatePlayer(&game->player, delta_time);                        // Изменение позиции игрока
    UpdateBullets(&game->bullets, &game->player, delta_time);       // Изменение позиции пули
    UpdateScore(&game->score);                          // Обновляем счет
}

// Рисуем паузу
void DrawPause(const GameState* game){
    if (game->game_state == GAME_STATE_PAUSED){
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0,0,0, 128});
        DrawText("PAUSE", SCREEN_WIDTH/2 - 35, SCREEN_HEIGHT/2, 20, WHITE);
    }    
}

void UpdatePause(GameState* game){
    if (IsKeyPressed(KEY_P)){
            if (game->game_state == GAME_STATE_PLAYING){
                game->game_state = GAME_STATE_PAUSED;
            } else if (game->game_state == GAME_STATE_PAUSED){
            game->game_state = GAME_STATE_PLAYING;
        }
    }
}

// Рисуем GameOver
void DrawGameOver(const GameState* game){
    if (game->game_state == GAME_STATE_GAMEOVER){
        DrawRectangle(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0, 0, 0, 128});
        DrawText("GAME OVER", SCREEN_WIDTH/2 - 35, SCREEN_HEIGHT/2, 20, RED);
        DrawText("Enter R to Restart", SCREEN_WIDTH/2 - 35, SCREEN_HEIGHT/2 + 30, 15, RED);
    }    
}

void UpdateGameOver(GameState* game){
    if (IsKeyPressed(KEY_D)){
        if (game->game_state == GAME_STATE_PLAYING){
            game->game_state = GAME_STATE_GAMEOVER;
        }           
    }
}

void ResetGame(GameState *game){
    if(IsKeyPressed(KEY_R)){
        if (game->game_state == GAME_STATE_GAMEOVER){
            game->game_state = GAME_STATE_PLAYING;
        }  
        game->player.position = startPosition;
        game->bullets.isActive = false;
        game->score.count = 0;
    }    
}