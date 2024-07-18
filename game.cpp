#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "scene.h"
#include "game.h"

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

int saveGame(){
    std::cout << "в разработке" << std::endl;
    while(IsESCKeyPress()){
    }
    return 0;
}

int loadGame(){
    std::cout << "в разработке" << std::endl;
    while(IsESCKeyPress()){
    }
    return 0;
}

int gameSeting(){
    std::cout << "в разработке" << std::endl;
    while(IsESCKeyPress()){
    }
    return 0;
}

int gameMenu(){
    unsigned short int choise;
    std::cout << "1.Продолжить" << std::endl;
    std::cout << "2.Сохранить" << std::endl;
    std::cout << "3.Загрузить" << std::endl;
    std::cout << "4.Настройки" << std::endl;
    std::cout << "5.Главное меню" << std::endl;
    std::cin >> choise;
    switch (choise)
    {
    case 1:
        return 0;
    
    case 2:
        saveGame();
        return 0;

    case 3:
        loadGame();
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
        std::string str;
        std::string txt;

        //на потом
        // unsigned short int limit;

        while(IsESCKeyPress()){
        while (!file.eof()){
            str = "";
            std::getline(file, str);
            Scene scn(str);
            txt = scn.getText();

            //на потом
            // limit = 0;
            // *Строка проверки*
            // std::cout << txt.size() << std::endl;
            
            for (short unsigned int i=0; i < txt.size(); i++){
                // limit++;
                
                //если кнопка нажата выводиться сразу весь текст
                if (!IsDialogueKeyPress()){
                    timeSleep = 0;
                }
                // if (!IsESCKeyPress()){
                //     return 0;
                // }

                std::cout << txt[i];

                //на потом
                // if (limit == 50){
                //     std::cout << std::endl;
                //     limit = 0;
                // }
                
                Sleep(timeSleep);
            }
            std::cout << std::endl;
            timeSleep = 2;

            // *Строка проверки*
            // std::cout << scn.getText() << " " << scn.getBackground() << " " << scn.getCharacter() << " " << scn.getEmote()  << std::endl;

            //пустой цикл не дающий продолжиться выполнению программы файла пока не будет нажата кнопка 
            while(IsDialogueKeyPress()){
                if (!IsESCKeyPress()){
                    if(gameMenu() == 5){
                        return 0;
                    };
                }
            };
        }
        }
    }
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

    switch (choise)
    {
    case 1:
        newGame(path, timeSleep);
        break;
    
    case 2:
        loadGame();
        break;

    case 3:
        std::cout << "В разработке" << std::endl;
        break;

    case 4:
        std::cout << "До скорых встреч";
        return abort();

    default:
        break;
    }
}