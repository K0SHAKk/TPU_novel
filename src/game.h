#ifndef GAME_H
#define GAME_H
#include <string>

class Game
{
public:
    std::string pathScene = "C:/practica/TPU_novel/scene.txt";
    unsigned short int timeSleep = 2;
    Game();
    ~Game();
    int mainMenu();
    int gameMenu();
    int startGame(int startLine);
};

#endif 