#ifndef SCENE_H
#define SCENE_H
#include <string>

class Scene
{
public:
    std::string text;
    int background;
    int character;
    int emote;
    Scene(std::string str);
    ~Scene();
};

Scene::Scene(std::string str){
    
}

#endif 