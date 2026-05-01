// WinStub для raylib - вызывает main.exe вместо WinMain@16

// Stub для WinMain - вызывает main.exe вместо WinMain@16
extern "C" int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;

    // Вызываем main.exe как консольное приложение
    return main();
}