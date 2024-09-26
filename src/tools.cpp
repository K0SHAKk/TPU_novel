#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

// функция отчистка консоли
void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

BOOL IsESCKeyPress() {
    if (_kbhit()) { // Проверяем, была ли нажата клавиша
        int ch = _getch(); // Получаем код нажатой клавиши
        if (ch == 27) { // 27 - код клавиши ESC
            return FALSE;
        }
    }
    return TRUE;
}

BOOL IsDialogueKeyPress() {
    if (_kbhit()) { // Проверяем, была ли нажата клавиша
        int ch = _getch(); // Получаем код нажатой клавиши
        if ((ch == 32) || (ch == 13)) { // 32, 13 - код клавиши Space, Enter
            return FALSE;
        }
    }
    return TRUE;
}