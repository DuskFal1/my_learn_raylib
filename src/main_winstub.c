#include "raylib.h"
#include <windows.h>

// Stub для WinMain - вызывает main.exe вместо WinMain@16
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // (void)hInstance;      // Убираем неиспользуемые параметры
    // (void)hPrevInstance;  // чтобы компилятор не ругался на GCC
    // (void)lpCmdLine;
    // (void)nCmdShow;

    // Вызываем main.exe как консольное приложение
    return main();
}