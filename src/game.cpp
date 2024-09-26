#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "scene.h"
#include "game.h"
#include "save.h"
#include "tools.h"

Save save2;

Game::Game()
{
}

Game::~Game()
{
}


// функция создающая главное меню
int Game::mainMenu(){
    clear();
    unsigned short int choise;
    std::cout << "Главное меню:" << std::endl;
    std::cout << "1. Новая игра" << std::endl;
    std::cout << "2. Загрузить игру" << std::endl;
    std::cout << "3. Выход" << std::endl;
    std::cin >> choise;
    clear();
    return choise;
}

// функция создающая меню паузы
int Game::gameMenu(){
    clear();
    unsigned short int choise;
    std::cout << "1.Продолжить" << std::endl;
    std::cout << "2.Сохранить" << std::endl;
    std::cout << "3.Главное меню" << std::endl;
    std::cin >> choise;
    clear();
    return choise;
}

int Game::startGame(int startLine){
    std::ifstream file;
    unsigned short int finalChoise;

    file.open(pathScene);

    //если файл не открывается, выыодит в консоль сообщение об ошибке открытия файла
    if (!file.is_open()){
        std::cout << "Ошибка открытия файла";
        return 0;
    }
    else{
        int tempTimeSleep = timeSleep;
        int curentLine = 0;
        std::string str;
        std::string txt;

        while (!file.eof()){
            str = "";
            std::getline(file, str);
            if (startLine <= (curentLine + 1)){
                Scene scn(str);
                txt = scn.getText();
                
                for (short unsigned int i=0; i < txt.size(); i++){
                    
                    //если кнопка нажата выводиться сразу весь текст
                    if (!IsDialogueKeyPress()){
                        tempTimeSleep = 0;
                    }
                    // if (!IsESCKeyPress()){
                    //     return 0;
                    // }

                    std::cout << txt[i];
                    
                    Sleep(tempTimeSleep);
                }
                std::cout << std::endl;
                tempTimeSleep = timeSleep;

                //цикл не дающий продолжиться выполнению программы файла пока не будет нажата клавиша Enter или Space. Если нажата клавиша Esc вызвает меню паузы
                while(IsDialogueKeyPress()){
                    if (!IsESCKeyPress()){
                        int choise = gameMenu();
                        if (choise == 1){
                            std::cout << txt << std::endl;
                            continue;
                        }
                        else if (choise == 2){
                            clear();
                            save2.saveGame(curentLine, txt);
                            save2.saveData();
                            save2.refreshData();
                            clear();
                            std::cout << txt << std::endl;
                        }
                        else if (choise == 3){
                            return 0;
                        }
                    }
                };
            }
            curentLine++;
        }
        std::cout << "Пойти в общежитие со всеми?" << std::endl;
        std::cout << "1 Да\n2 нет" << std::endl;
        std::cin >> finalChoise;
        if (finalChoise == 1){
            std::cout << "Вы возвращаетесь в общежитие со всеми";
        }
        else if (finalChoise == 2){
            std::cout << "Вы решаете прогуляться одни по городу";
        }
        while(IsDialogueKeyPress()){
            if (!IsESCKeyPress()){
                int choise = gameMenu();
                if (choise == 1){
                    std::cout << txt << std::endl;
                    continue;
                }
                else if (choise == 2){
                    clear();
                    save2.saveGame(curentLine, txt);
                    save2.saveData();
                    save2.refreshData();
                    clear();
                    std::cout << txt << std::endl;
                }
                else if (choise == 3){
                    return 0;
                }
            }
        };
    }
    clear();
    return 0;
}