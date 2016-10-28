#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

namespace ErzatzKnight {
    class ResourceManager {
    public:
        static ResourceManager * getInstance();
		static void deleteInstance();
        sf::Font * getFont(string name);
        sf::Sound * getSound(string name);
        sf::Music * getMusic(string name);
        sf::Texture * getTexture(string name);

    private:
        static ResourceManager * manager;
        string path;

        map<string, sf::Font*> fonts;
        map<string, sf::Sound *> sounds;
        map<string, sf::Music *> musics;
        map<string, sf::Texture *> textures;

        ResourceManager(string path);
        ~ResourceManager();
    };
}

#endif