#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "scene.h"

//функция проверяющая нажатие клавишь на клавиатуре
BOOL IsKeyPress() {
    HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD event;
    DWORD count;
 
    if (WaitForSingleObject(handle, 0) == WAIT_OBJECT_0) {
        ReadConsoleInput(handle, &event, 1, &count);
        return ((event.EventType == KEY_EVENT) && event.Event.KeyEvent.bKeyDown);
    }
 
    return true;
}

int main(int, char**){
    setlocale(LC_ALL, "ru");
    
    //переменная хранящая путь до файла с текстом
    std::string path = "C:/practica/TPU_novel/scene.txt";

    std::ifstream file;
    file.open(path);

    //если файл не открывается, выыодит в консоль сообщение об ошибке открытия файла
    if (!file.is_open()){
        std::cout << "Ошибка открытия файла";
    }
    else{
        std::string str;

        while (!file.eof()){
            str = "";
            std::getline(file, str);
            Scene scn(str);
            std::cout << scn.getText() << " " << scn.getBackground() << " " << scn.getCharacter() << " " << scn.getEmote() << std::endl;

            //пустой цикл не дающий продолдиться выполнению программы файла пока не будет нажата кнопка 
            while(IsKeyPress()){
            };
        }
    }
    return 0;
}