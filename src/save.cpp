#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "save.h"
#include "tools.h"

Save::Save()
{
    std::ifstream file;
    file.open(pathSave);

    //если файл не открывается, выыодит в консоль сообщение об ошибке открытия файла
    if (!file.is_open()){
        std::cout << "Ошибка открытия файла";
    }
    else{
        unsigned short int i = 0;
        while (!file.eof()){
            std::string str = "";
            std::getline(file, str);
            std::vector<std::string> arr;
            std::string delim("; ");
            size_t prev = 0;
            size_t next;
            size_t delta = delim.length();

            while( ( next = str.find( delim, prev ) ) != std::string::npos ){
                //Отладка-start
                std::string tmp = str.substr( prev, next-prev );
                //Отладка-end
                arr.push_back( str.substr( prev, next-prev ) );
                prev = next + delta;
                }
            //Отладка-start
            std::string tmp = str.substr( prev );
            //Отладка-end
            arr.push_back( str.substr( prev ) );
            saveslotnumber[i] = std::stoi(arr[0]);
            saveslot[i] = arr[1];
            i++;
        }
        i = 0;
    }
    file.close();
}

Save::~Save()
{
    std::ofstream outFile(pathSave);

    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
    }
    else{
        for (int i = 0; i < 10; ++i) {
            if (i < 9){
                outFile << saveslotnumber[i] <<"; "<< saveslot[i] << std::endl;
            }
            else{
                outFile << saveslotnumber[i] <<"; "<< saveslot[i];
            }
        }
    }

    outFile.close();
}

void Save::saveGame(unsigned short int line, std::string str){
    unsigned short int slot;
    std::cout << "Выберите слот сохранения:" << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << "Слот " << i+1 << " " << saveslot[i] << std::endl; 
    }
    std::cin >> slot;
    if (slot == 0){
        std::cout << "Нет слота" << std::endl;
    }
    else{
        saveslot[slot-1] = str;
        saveslotnumber[slot-1] = line+1;
    }
}

int Save::loadGame(){
    clear();
    int slot;
    std::cout << "Выберите слот Загрузки:" << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << "Слот " << i+1 << " " << saveslot[i] << std::endl; 
    }
    std::cin >> slot;
    return saveslotnumber[slot-1];
}

void Save::refreshData(){
    std::ifstream file;
    file.open(pathSave);

    //если файл не открывается, выыодит в консоль сообщение об ошибке открытия файла
    if (!file.is_open()){
        std::cout << "Ошибка открытия файла";
    }
    else{
        unsigned short int i = 0;
        while (!file.eof()){
            std::string str = "";
            std::getline(file, str);
            std::vector<std::string> arr;
            std::string delim("; ");
            size_t prev = 0;
            size_t next;
            size_t delta = delim.length();

            while( ( next = str.find( delim, prev ) ) != std::string::npos ){
                //Отладка-start
                std::string tmp = str.substr( prev, next-prev );
                //Отладка-end
                arr.push_back( str.substr( prev, next-prev ) );
                prev = next + delta;
                }
            //Отладка-start
            std::string tmp = str.substr( prev );
            //Отладка-end
            arr.push_back( str.substr( prev ) );
            saveslotnumber[i] = std::stoi(arr[0]);
            saveslot[i] = arr[1];
            i++;
        }
        i = 0;
    }
    file.close();
}

void Save::saveData(){
    std::ofstream outFile(pathSave);

    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
    }
    else{
        for (int i = 0; i < 10; ++i) {
            if (i < 9){
                outFile << saveslotnumber[i] <<"; "<< saveslot[i] << std::endl;
            }
            else{
                outFile << saveslotnumber[i] <<"; "<< saveslot[i];
            }
        }
    }

    outFile.close();
}