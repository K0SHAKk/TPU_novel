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
    
    //время через которое будет выводиться следующий смвол
    unsigned short int timeSleep = 3;

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
        std::string txt;

        //на потом
        // unsigned short int limit;

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
                if (!IsKeyPress()){
                    timeSleep = 0;
                }

                std::cout << txt[i];

                //на потом
                // if (limit == 50){
                //     std::cout << std::endl;
                //     limit = 0;
                // }
                
                Sleep(timeSleep);
            }
            std::cout << std::endl;
            timeSleep = 3;

            // *Строка проверки*
            // std::cout << scn.getText() << " " << scn.getBackground() << " " << scn.getCharacter() << " " << scn.getEmote()  << std::endl;

            //пустой цикл не дающий продолдиться выполнению программы файла пока не будет нажата кнопка 
            while(IsKeyPress()){
            };
        }
    }
    return 0;
}