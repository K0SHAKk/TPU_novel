#include <string>
#include <iostream>
#include <vector>
#include "scene.h"

// функция из полученой строки достаёт детали сцены которые разделены знаком ";"
Scene::Scene(std::string str){
    std::vector<std::string> arr;
    std::string delim("; ");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    // через цикл в массив записывается чтроки разделёные знаком ";" 
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

    // строки из массива записывауться в переменые text, background, character, emote для дальнейшего использования в создании графической сцены
    text = arr[0];
    background = arr[1];
    character = arr[2];
    emote = arr[3];

}

Scene::~Scene(){
};

std::string Scene::getText(){
    return text;
}

std::string Scene::getBackground(){
    return background;
}

std::string Scene::getCharacter(){
    return character;
}
std::string Scene::getEmote(){
    return emote;
}