#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "scene.h"
#include "game.h"
#include "save.h"

std::string path = "C:/practica/TPU_novel/save.txt";
Save save(path);

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
//функция проверяющая нажатие клавишь на клавиатуре
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
        if ((ch == 32) or (ch == 13)) { // 32, 13 - код клавиши Space, Enter
            return FALSE;
        }
    }
    return TRUE;
}

int gameSeting(){
    std::cout << "в разработке" << std::endl;
    while(IsESCKeyPress()){
    }
    return 0;
}

// int continueGame(std::string path, unsigned short int timeSleep, int saveLine){
//     std::ifstream file;

//     file.open(path);

//     //если файл не открывается, выыодит в консоль сообщение об ошибке открытия файла
//     if (!file.is_open()){
//         std::cout << "Ошибка открытия файла";
//     }
//     else{
//         unsigned short int line = 0;
//         std::string str;
//         std::string txt;

//         while (!file.eof()){
//             unsigned short int curentLine = 0;
//             if (curentLine >= saveLine){
//                 str = "";
//                 std::getline(file, str);
//                 Scene scn(str);
//                 txt = scn.getText();
                
//                 for (short unsigned int i=0; i < txt.size(); i++){
                    
//                     //если кнопка нажата выводиться сразу весь текст
//                     if (!IsDialogueKeyPress()){
//                         timeSleep = 0;
//                     }
//                     // if (!IsESCKeyPress()){
//                     //     return 0;
//                     // }

//                     std::cout << txt[i];
                    
//                     Sleep(timeSleep);
//                 }
//                 std::cout << std::endl;
//                 timeSleep = 2;
//                 line++;

//                 // *Строка проверки*
//                 // std::cout << scn.getText() << " " << scn.getBackground() << " " << scn.getCharacter() << " " << scn.getEmote()  << std::endl;

//                 //пустой цикл не дающий продолжиться выполнению программы файла пока не будет нажата кнопка 
//                 while(IsDialogueKeyPress()){
//                     if (!IsESCKeyPress()){
//                         clear();
//                         if(gameMenu(line, txt) == 5){
//                             clear();
//                             return 0;
//                         };
//                     }
//                 };
//             }
//             curentLine ++;
//         }
//     }
//     clear();
//     return 0;
// }

int gameMenu(unsigned short int line, std::string str){
    clear();
    unsigned short int choise;
    std::cout << "1.Продолжить" << std::endl;
    std::cout << "2.Сохранить" << std::endl;
    std::cout << "3.Загрузить" << std::endl;
    std::cout << "4.Настройки" << std::endl;
    std::cout << "5.Главное меню" << std::endl;
    std::cin >> choise;
    clear();
    switch (choise)
    {
    case 1:
        return 0;
    
    case 2:
        save.saveGame(line, str);
        return 0;

    case 3:
        save.loadGame();
        return 0;

    case 4:
        gameSeting();
        return 0;

    case 5:
        return 5;

    default:
        return 0;
    }
}

int newGame(std::string path, unsigned short int timeSleep){
    std::ifstream file;

    file.open(path);

    //если файл не открывается, выыодит в консоль сообщение об ошибке открытия файла
    if (!file.is_open()){
        std::cout << "Ошибка открытия файла";
    }
    else{
        unsigned short int line = 0;
        std::string str;
        std::string txt;

        while (!file.eof()){
            str = "";
            std::getline(file, str);
            Scene scn(str);
            txt = scn.getText();
            
            for (short unsigned int i=0; i < txt.size(); i++){
                
                //если кнопка нажата выводиться сразу весь текст
                if (!IsDialogueKeyPress()){
                    timeSleep = 0;
                }
                // if (!IsESCKeyPress()){
                //     return 0;
                // }

                std::cout << txt[i];
                
                Sleep(timeSleep);
            }
            std::cout << std::endl;
            timeSleep = 2;
            line++;

            // *Строка проверки*
            // std::cout << scn.getText() << " " << scn.getBackground() << " " << scn.getCharacter() << " " << scn.getEmote()  << std::endl;

            //пустой цикл не дающий продолжиться выполнению программы файла пока не будет нажата кнопка 
            while(IsDialogueKeyPress()){
                if (!IsESCKeyPress()){
                    clear();
                    if(gameMenu(line, txt) == 5){
                        clear();
                        return 0;
                    };
                }
            };
        }
    }
    clear();
    return 0;
}

void mainMenu(std::string path, unsigned short int timeSleep){
    unsigned short int choise;
    std::cout << "Главное меню:" << std::endl;
    std::cout << "1. Новая игра" << std::endl;
    std::cout << "2. Загрузить игру" << std::endl;
    std::cout << "3. Настройки" << std::endl;
    std::cout << "4. Выход" << std::endl;
    std::cin >> choise;
    clear();
    switch (choise)
    {
    case 1:
        newGame(path, timeSleep);
        break;
    
    case 2:
        save.loadGame();
        break;

    case 3:
        std::cout << "В разработке" << std::endl;
        break;

    case 4:
        std::cout << "До скорых встреч";
        save.~Save();
        return abort();

    default:
        break;
    }
}