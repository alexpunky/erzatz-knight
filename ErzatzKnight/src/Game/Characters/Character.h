#ifndef CHARACTER_H
#define CHARACTER_H

#include <Graphics/Animation.hpp>
#include <Graphics/AnimatedSprite.hpp>
#include <SFML/Audio.hpp>
#include <Config/Types.h>

using namespace sf;


namespace ErzatzKnight {
    class Character {
    protected:
        //string id;
        bool immortal;
        int hp;
        Animation * left;
        Animation * right;
        Animation * up;
        Animation * down;

        Direction direction;
        //Point position;

    public:
        AnimatedSprite * sprite;
        sf::Sound * sound;
        Character(int hp, bool immortal);
        Character();
        ~Character();

        void setDirectionLeft();
        void setDirectionRight();
        void setDirectionUp();
        void setDirectionDown();

        void inflictDamage(int damage);
        //Point getPosition();
        //void move(Point pos);
    };
}

#endif