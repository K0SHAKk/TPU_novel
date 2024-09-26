#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "scene.h"
#include "game.h"
#include "save.h"
#include "tools.h"

Save save;
Game game;

int main(int, char**){
    setlocale(LC_ALL, "ru");
    BOOL running = true;

    do{
        clear();
        save.refreshData();
        int choice = game.mainMenu();
        if(choice == 1){
            game.startGame(0);
        }
        else if(choice == 2){
            clear();
            int startLine = save.loadGame();
            std::cout << startLine << std::endl;
            game.startGame(startLine);
        }
        else if(choice == 3){
            clear();
            std::cout << "До скорых встреч" << std::endl;
            running = false;
        }
    }
    while (running);

    // save.~Save();
    return 0;
}