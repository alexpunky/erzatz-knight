#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Graphics/AnimatedSprite.hpp>


using namespace std;
using namespace sf;
using namespace ErzatzKnight;

Character::Character(/*string id, */int hp, bool immortal) {
    this->hp = hp;
    this->immortal = immortal;
    Texture * texture = new Texture();
    texture->loadFromFile("resources/textures/zelda.png");

    this->left = new Animation();
    this->left->setSpriteSheet(*texture);
    this->left->addFrame(sf::IntRect(5, 0, 23, 34));
    this->left->addFrame(sf::IntRect(28, 0, 23, 34));
    this->left->addFrame(sf::IntRect(51, 0, 23, 34));
    this->left->addFrame(sf::IntRect(74, 0, 23, 34));
    this->left->addFrame(sf::IntRect(97, 0, 23, 34));
    this->left->addFrame(sf::IntRect(120, 0, 23, 34));
    this->left->addFrame(sf::IntRect(143, 0, 23, 34));
    this->left->addFrame(sf::IntRect(166, 0, 23, 34));

    this->right = new Animation();
    this->right->setSpriteSheet(*texture);
    this->right->addFrame(sf::IntRect(191, 0, 23, 34));
    this->right->addFrame(sf::IntRect(214, 0, 23, 34));
    this->right->addFrame(sf::IntRect(237, 0, 23, 34));
    this->right->addFrame(sf::IntRect(259, 0, 23, 34));
    this->right->addFrame(sf::IntRect(282, 0, 23, 34));
    this->right->addFrame(sf::IntRect(305, 0, 23, 34));
    this->right->addFrame(sf::IntRect(328, 0, 23, 34));
    this->right->addFrame(sf::IntRect(351, 0, 23, 34));

    this->up = new Animation();
    this->up->setSpriteSheet(*texture);
    this->up->addFrame(sf::IntRect(5, 34, 23, 34));
    this->up->addFrame(sf::IntRect(28, 34, 23, 34));
    this->up->addFrame(sf::IntRect(51, 34, 23, 34));
    this->up->addFrame(sf::IntRect(74, 34, 23, 34));
    this->up->addFrame(sf::IntRect(97, 34, 23, 34));
    this->up->addFrame(sf::IntRect(120, 34, 23, 34));
    this->up->addFrame(sf::IntRect(143, 34, 23, 34));
    this->up->addFrame(sf::IntRect(166, 34, 23, 34));

    this->down = new Animation();
    this->down->setSpriteSheet(*texture);
    this->down->addFrame(sf::IntRect(192, 34, 23, 34));
    this->down->addFrame(sf::IntRect(215, 34, 23, 34));
    this->down->addFrame(sf::IntRect(238, 34, 23, 34));
    this->down->addFrame(sf::IntRect(261, 34, 23, 34));
    this->down->addFrame(sf::IntRect(284, 34, 23, 34));
    this->down->addFrame(sf::IntRect(307, 34, 23, 34));
    this->down->addFrame(sf::IntRect(330, 34, 23, 34));
    this->down->addFrame(sf::IntRect(353, 34, 23, 34));

    this->sprite = new AnimatedSprite(sf::seconds(0.1));
    this->sprite->setAnimation(*this->left);
    this->sprite->scale(2.0f, 2.0f);
    this->sprite->setPosition(0, 0);
    this->direction = Direction::LEFT;


    //this->id = id;
    //this->position.x = 0;
    //this->position.y = 0;
}

Character::Character() {
    this->hp = 0;
    this->immortal = true;
    //this->id = "UNDEFINED";
    //this->position.x = 0;
    //this->position.y = 0;
}

Character::~Character() {
    delete(this->sprite);
    delete(this->left);
    delete(this->right);
    delete(this->up);
    delete(this->down);
}

void Character::setDirectionLeft() {
    if(this->direction != Direction::LEFT) {
        this->direction = Direction::LEFT;
        this->sprite->setAnimation(*this->left);
    }
}

void Character::setDirectionRight() {
    if(this->direction != Direction::RIGHT) {
        this->direction = Direction::RIGHT;
        this->sprite->setAnimation(*this->right);
    }
}

void Character::setDirectionUp() {
    if(this->direction != Direction::UP) {
        this->direction = Direction::UP;
        this->sprite->setAnimation(*this->up);
    }
}

void Character::setDirectionDown() {
    if(this->direction != Direction::DOWN) {
        this->direction = Direction::DOWN;
        this->sprite->setAnimation(*this->down);
    }
}

void Character::inflictDamage(int damage) {
    if(this->immortal) {
        cout << "yé souis immortel tou pé pa mé toué" << endl;
    }
    else {
        if(this->hp >= 0) {
            this->hp -= damage;
            cout << "HP restant : " << this->hp << endl;
        }
        else {
            cout << "yé souis déya mol :(" << endl;
        }
    }
}

/*Point Character::getPosition() { 
return this->position;
}

void Character::move(Point pos) {
this->position.x += pos.x;
this->position.y += pos.y;
}*/
