
@echo off
chcp 65001 >nul 2>&1
title Меню сборки игры
color 0B

:menu
cls
echo.
echo ========================================
echo        МЕНЮ СБОРКИ ИГРЫ
echo ========================================
echo.
echo   1. Собрать игру (make)
echo   2. Собрать и запустить (make run)
echo   3. Очистить проект (make clean)
echo   4. Пересобрать (make rebuild)
echo   5. Справка (make help)
echo   6. Выход
echo.
echo ========================================
echo.
set /p choice="Выберите действие (1-6): "

if "%choice%"=="1" goto build
if "%choice%"=="2" goto run
if "%choice%"=="3" goto clean
if "%choice%"=="4" goto rebuild
if "%choice%"=="5" goto help
if "%choice%"=="6" goto exit
goto menu

:build
cls
mingw32-make -f Makefile.win
pause
goto menu

:run
cls
mingw32-make -f Makefile.win run
pause
goto menu

:clean
cls
mingw32-make -f Makefile.win clean
pause
goto menu

:rebuild
cls
mingw32-make -f Makefile.win rebuild
pause
goto menu

:help
cls
mingw32-make -f Makefile.win help
pause
goto menu

:exit
chcp 866 >nul
exit