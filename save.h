#ifndef SAVE_H
#define SAVE_H
#include <string>
#include <list>

class Save
{
public:
    std::string pathSave = "C:/practica/TPU_novel/save.txt";
    unsigned short int saveslotnumber[10] = {0};
    std::string saveslot[10] = {"Пусто","Пусто","Пусто","Пусто","Пусто","Пусто","Пусто","Пусто","Пусто","Пусто"};
    Save();
    ~Save();
    void saveGame(unsigned short int line, std::string str);
    int loadGame();
    void refreshData();
    void saveData();
};

#endif