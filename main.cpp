#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "scene.h"
#include "game.h"

int main(int, char**){
    setlocale(LC_ALL, "ru");
    //время через которое будет выводиться следующий смвол
    unsigned short int timeSleep = 2;
    //переменная хранящая путь до файла с текстом
    std::string path = "C:/practica/TPU_novel/scene.txt";
    
    while (true){
        mainMenu(path, timeSleep);
    }
    return 0;
}