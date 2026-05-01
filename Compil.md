# Сборка игры Raylib на Windows 🎮

## Требования

- **Windows 10/11**
- **Raylib**: `C:\raylib\` (содержит `include`, `lib`)
- **GCC/MingW32**: установлен в системе

---

## Структура проекта

```
my_learn_raylib/
├── src/           # Исходные файлы (.c)
│   ├── main.c     # Основной файл
│   ├── game.c
│   ├── menu.c
│   ├── ui.c
│   ├── bullets.c
│   ├── enemy.c
│   └── player.c
├── include/       # Header файлы (.h)
├── build/         # Сборка (object-файлы и exe)
└── Compil.md      # Инструкция по сборке
```

---

## Быстрый запуск игры

```batch
# Перейти в директорию проекта
cd e:\Raylib\my_learn_raylib

# Запустить игру
cmd /c "start "" my_learn_raylib/build/game.exe""
```

---

## Команды mingw32-make

```batch
# Сборка проекта (создаст game.exe)
mingw32-make -f Makefile.win all

# Сборка + запуск игры
mingw32-make -f Makefile.win run

# Очистка (удаление всех скомпилированных файлов)
mingw32-make -f Makefile.win clean

# Полная пересборка (очистка + новая сборка)
mingw32-make -f Makefile.win rebuild

# Показать доступные команды
mingw32-make -f Makefile.win help
```

---

## Ручная компиляция

Если `mingw32-make` не работает, можно использовать прямые команды gcc:

### 1. Компиляция всех исходных файлов в object-файлы

```batch
# Создаём директорию сборки (если нет)
if not exist build mkdir build

# main.c
gcc -Wall -Wextra -std=c11 -mwindows -c "e:/Raylib/my_learn_raylib/src/main.c" ^
  -o build/main.o -I"e:/Raylib/my_learn_raylib/include"

# game.c
gcc -Wall -Wextra -std=c11 -mwindows -c "e:/Raylib/my_learn_raylib/src/game.c" ^
  -o build/game.o -I"e:/Raylib/my_learn_raylib/include"

# menu.c
gcc -c "e:/Raylib/my_learn_raylib/src/menu.c" ^
  -o build/menu.o -I"e:/Raylib/my_learn_raylib/include"

# bullets.c
gcc -c "e:/Raylib/my_learn_raylib/src/bullets.c" ^
  -o build/bullets.o -I"e:/Raylib/my_learn_raylib/include"

# enemy.c
gcc -c "e:/Raylib/my_learn_raylib/src/enemy.c" ^
  -o build/enemy.o -I"e:/Raylib/my_learn_raylib/include"

# player.c
gcc -c "e:/Raylib/my_learn_raylib/src/player.c" ^
  -o build/player.o -I"e:/Raylib/my_learn_raylib/include"

# ui.c
gcc -c "e:/Raylib/my_learn_raylib/src/ui.c" ^
  -o build/ui.o -I"e:/Raylib/my_learn_raylib/include"
```

### 2. Связывание (линковка) исполняемого файла

```batch
gcc -mwindows ^
  build/game.o build/menu.o build/bullets.o build/enemy.o ^
  build/player.o build/ui.o "C:/raylib/lib/libraylib.a" build/main.o ^
  -o my_learn_raylib/build/game.exe -lopengl32 -lgdi32 -lwinmm
```

### 3. Запуск игры

```batch
cmd /c "start "" my_learn_raylib/build/game.exe""
```

---

## Полный процесс одной командой

```batch
cd e:\Raylib\my_learn_raylib

# Одна команда для полной сборки:
gcc -mwindows ^
  "e:/Raylib/my_learn_raylib/src/main.c" ^
  "e:/Raylib/my_learn_raylib/src/game.c" ^
  "e:/Raylib/my_learn_raylib/src/menu.c" ^
  "e:/Raylib/my_learn_raylib/src/bullets.c" ^
  "e:/Raylib/my_learn_raylib/src/enemy.c" ^
  "e:/Raylib/my_learn_raylib/src/player.c" ^
  "e:/Raylib/my_learn_raylib/src/ui.c" ^
  -I"e:/Raylib/my_learn_raylib/include" ^
  -o my_learn_raylib/build/game.exe ^
  "C:/raylib/lib/libraylib.a" ^
  -lopengl32 -lgdi32 -lwinmm

# Запуск:
start "" my_learn_raylib/build/game.exe
```

---

## Путь к исполняемому файлу

```
e:\Raylib\my_learn_raylib\build\game.exe
```

---

## Ошибки и решения

### Ошибка: `undefined reference to 'WinMain@16'`

**Причина**: Используется MinGW32 (32-bit), но нужен 32-bit stub.

**Решение**: Добавлять флаг `-mwindows` при линковке — это создаёт консольное окно вместо требования WinMain.

### Ошибка: `raylib.h: No such file or directory`

**Причина**: Raylib не установлен в правильном месте.

**Решение**: Установить Raylib в `C:\raylib\` или указать путь через `-I`:
```batch
-I"C:/raylib/include"
```

### Ошибка: `C:\MinGW\bin/../lib/gcc/.../ld.exe`

**Причина**: Используются старые зависимости MinGW.

**Решение**: При линковке явно указывайте библиотеки Raylib:
```batch
"C:/raylib/lib/libraylib.a"
```

---

## Полезные ссылки

- [Raylib GitHub](https://github.com/raysan5/raylib)
- [Raylib Wiki](https://www.raylib.com/)
- [MinGW Downloads](https://sourceforge.net/projects/mingw/)