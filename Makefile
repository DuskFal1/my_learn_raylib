CC=clang
CFLAGS=-Wall -std=c99 -I./include -I/opt/homebrew/include
LDFLAGS=-L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
TARGET=my_game

SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c, build/%.o, $(SRCS))

all: build_dir $(TARGET)

build_dir:
	@mkdir -p build

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "✅ Игра собрана из $(words $(SRCS)) файлов!"

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@echo "🚀 Запуск игры..."
	./$(TARGET)

clean:
	rm -rf build $(TARGET)
	@echo "🧹 Очищено"

.PHONY: all run clean build_dir