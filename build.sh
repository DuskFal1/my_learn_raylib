#!/bin/bash
echo "🔨 Компиляция игры..."
clang src/main.c src/game.c -o my_game \
    -I./include \
    -I/opt/homebrew/include \
    -L/opt/homebrew/lib \
    -lraylib \
    -framework OpenGL \
    -framework Cocoa \
    -framework IOKit \
    -framework CoreVideo \
    -Wall -std=c99

if [ $? -eq 0 ]; then
    echo "✅ Игра собрана!"
    echo "🚀 Запуск..."
    ./my_game
else
    echo "❌ Ошибка компиляции"
fi
