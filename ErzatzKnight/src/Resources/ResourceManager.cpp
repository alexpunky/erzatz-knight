#include "ResourceManager.h"
//#include <SFML/Graphics.hpp>
#include <map>

using namespace ErzatzKnight;
using namespace sf;

ResourceManager * ResourceManager::manager = new ResourceManager("resources/");

ResourceManager * ResourceManager::getInstance() {
    return ResourceManager::manager;
}

void ResourceManager::deleteInstance() {
	delete ResourceManager::manager;
	ResourceManager::manager = 0;
}

sf::Font * ResourceManager::getFont(string name) {
    if(this->fonts.find(name) == this->fonts.end()) {
        sf::Font * font = new sf::Font();
        font->loadFromFile(this->path + "fonts/" + name);
        this->fonts[name] = font;
    }
    return this->fonts[name];
}

sf::Sound * ResourceManager::getSound(string name) {
    if(this->sounds.find(name) == this->sounds.end()) {
		sf::SoundBuffer * soundBuffer = new SoundBuffer();
        bool loaded = soundBuffer->loadFromFile(this->path + "sounds/"+name);
        this->sounds[name] = new Sound(*soundBuffer);
    }
    return this->sounds[name];
}

sf::Music * ResourceManager::getMusic(string name) {
    if(this->musics.find(name) == this->musics.end()) {
        sf::Music * music = new Music();
        music->openFromFile(name);
        this->musics[name] = music;
    }
    return this->musics[name];
}

sf::Texture * ResourceManager::getTexture(string name) {
    if(this->textures.find(name) == this->textures.end()) {
        Texture *tex = new Texture();
        if (!tex->loadFromFile(this->path + "textures/" + name))
        {
            cout << "Oh no, the texture is not here :( >> " << name << endl;
        }

        tex->setSmooth(true);
        this->textures[name] = tex;
    }
    return this->textures[name];
}

ResourceManager::ResourceManager(string path) {
    this->path = path;
}

ResourceManager::~ResourceManager() {
    map<string, sf::Texture*>::iterator it_texture = this->textures.begin();
	while(it_texture != this->textures.end()) {
		delete it_texture->second;
		it_texture++;
	}
	this->textures.clear();
	
	map<string, sf::Font*>::iterator it_font = this->fonts.begin();
	while(it_font != this->fonts.end()) {
		delete it_font->second;
		it_font++;
	}
	this->fonts.clear();

	map<string, sf::Sound*>::iterator it_sound = this->sounds.begin();
	while(it_sound != this->sounds.end()) {
		delete it_sound->second;
		it_sound++;
	}
	this->sounds.clear();

	map<string, sf::Music*>::iterator it_music = this->musics.begin();
	while(it_music != this->musics.end()) {
		delete it_music->second;
		it_music++;
	}
	this->musics.clear();
	cout << "Clean complete" << endl;
}