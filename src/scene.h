#ifndef SCENE_H
#define SCENE_H
#include <string>


class Scene
{
public:
    std::string text;
    std::string background;
    std::string character;
    std::string emote;
    Scene(std::string str);
    ~Scene();

    std::string getText();
    std::string getBackground();
    std::string getCharacter();
    std::string getEmote();
};

#endif 