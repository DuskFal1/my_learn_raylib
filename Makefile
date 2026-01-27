CC=clang
CFLAGS=-Wall -std=c99 -I./include -I/opt/homebrew/include -MMD
LDFLAGS=-L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
TARGET=my_game

SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c, build/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)
ASSETS_DIR=assets
ASSETS=$(wildcard $(ASSETS_DIR)/*)


all: build_dir $(TARGET)

copy_assets: $(ASSETS)
	@mkdir -p $(BUILD_DIR)./assets
	@cp -r $(ASSETS_DIR)/* $(BUILD_DIR)/assets/ 2>/dev/null || true
	@echo "📦 Ресурсы скопированы"

build_dir:
	@mkdir -p build

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "✅ Игра собрана из $(words $(SRCS)) файлов!"

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET) copy_assets
	@echo "🚀 Запуск игры..."
	./$(TARGET)

clean:
	rm -rf build $(TARGET)
	@echo "🧹 Очищено"

-include $(DEPS)

.PHONY: all run clean build_dir