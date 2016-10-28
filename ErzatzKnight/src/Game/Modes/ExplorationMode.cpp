#include "ExplorationMode.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Sound/SoundEngine.h>
#include <Game/Game.h>

using namespace std;
using namespace ErzatzKnight::Modes;
using namespace sf;

ExplorationMode::ExplorationMode(Game& game, int width, int height) : Mode(game, width, height) {
    this->posx = 0;
    this->posy = 0;
    this->hero = new Character(100, false);
    this->hero->sprite->setPosition(600, 400);
    this->map = new Map(100,100, this->hero);
    this->tile_size = (int)floor(50 * this->ratio);
    if(this->tile_size % 2 == 1) { this->tile_size--; }
    this->mid_tile_size = this->tile_size / 2;
}

ExplorationMode::~ExplorationMode() {
    delete this->map;
    delete this->hero;
}

bool ExplorationMode::canMoveRight() {
    return true;
}

bool ExplorationMode::canMoveLeft() {
    return true;
}

bool ExplorationMode::canMoveUp() {
    return true;
}

bool ExplorationMode::canMoveDown() {
    return true;
}

void ExplorationMode::display() {
    int maxx = (int)ceil((double)(this->width/2+this->mid_tile_size - this->posx)/this->tile_size);
    int maxy = (int)ceil((double)(this->mid_tile_size +(this->height/2) - this->posy)/this->tile_size);
    int minx = (int)floor((double)(this->mid_tile_size -(this->width/2) - this->posx)/this->tile_size);
    int miny = (int)floor((double)(this->mid_tile_size -(this->height/2) - this->posy)/this->tile_size);

    if(minx<0) minx = 0;
    if(miny<0) miny = 0;
    if(maxx>this->map->getWidth()) maxx = this->map->getWidth();
    if(maxy>this->map->getHeight()) maxy = this->map->getHeight();

    //cout << (maxx - minx) * (maxy - miny) << endl;

    for(int i = minx; i < maxx; i++) {
        for(int j = miny; j < maxy; j++) {
            Sprite sprite;
            sprite.setTexture(*this->map->getCell(i, j)->getTexture());
            sprite.setPosition(i*this->tile_size - this->mid_tile_size + this->posx + this->width/2, j*this->tile_size - this->mid_tile_size + this->posy + this->height/2);

            sprite.setScale(this->ratio, this->ratio);
            this->game->draw(sprite);
        }
    }
	this->hero->sprite->update(this->game->resetClock());
    this->hero->sprite->play();
    this->hero->sprite->setScale(this->ratio, this->ratio);
    this->game->draw(*this->hero->sprite);
}

void ExplorationMode::manageEvents() {
    /*this->posx -=5;
    this->posy -= 5;*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(this->canMoveRight()) {
            this->posx -= 5;
        }
        hero->setDirectionRight();
        /*hero->playAnimation();
        pos.x = 5;
        pos.y = 0;
        hero->move(pos);*/
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(this->canMoveLeft()) {
            this->posx += 5;
        }
        hero->setDirectionLeft(); 
        /*hero->playAnimation();
        pos.x = -5;
        pos.y = 0;
        hero->move(pos);*/
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(this->canMoveDown()) {
            this->posy -= 5;
        }
        hero->setDirectionDown();
        /*hero->playAnimation();
        pos.x = 0;
        pos.y = 5;
        hero->move(pos);*/
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(this->canMoveUp()) {
            this->posy += 5;
        }
        hero->setDirectionUp(); 
        /*hero->playAnimation();
        pos.x = 0;
        pos.y = -5;
        hero->move(pos);*/
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        sf::Sound * sound = ResourceManager::getInstance()->getSound("biggun3.wav");
        sound->setVolume(10);
        sound->play();
    }

    /*if(Input.IsKeyDown(sf::Key::Space)) {
    hero->inflictDamage(2);
    }*/
}

void ExplorationMode::managePollEvent(sf::Event event) {
    switch(event.type) {
    case sf::Event::KeyPressed:
        switch(event.key.code) {
        case  sf::Keyboard::Escape:
            this->game->quit();
            break; 
        case sf::Keyboard::P:
            this->game->switchToMenu();
            break;
        }
        break;
    }
}

void ExplorationMode::changeSize(int width, int height) {
    Mode::changeSize(width, height);
    
    this->tile_size = (int)floor(50 * this->ratio);
    if(this->tile_size % 2 == 1) { this->tile_size--; }
    this->mid_tile_size = this->tile_size / 2;
    this->posx = this->posx * this->ratio;
    this->posy = this->posy * this->ratio;
    
}
