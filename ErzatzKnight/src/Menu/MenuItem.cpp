#include "MenuItem.h"
#include <SFML/Graphics/Text.hpp>
#include <Resources/ResourceManager.h>
#include <Config/Logger.hpp>

using namespace sf;
using namespace ErzatzKnight;
using namespace ErzatzKnight::Menus;

MenuItem::MenuItem(string value, int posx, int posy, std::function<void(void)> callback) {
	*FileLogger::getInstance() << FileLogger::e_logType::LOG_INFO << "Create menu item" << value; 
	sf::Text * on = new sf::Text(value, *ResourceManager::getInstance()->getFont("arial.ttf"));
	on->setCharacterSize(30);
    on->setStyle(sf::Text::Bold);
	on->setColor(sf::Color::Red);
	on->setPosition(posx, posy);
	this->onSprite = on;
	
	sf::Text * off = new sf::Text(value, *ResourceManager::getInstance()->getFont("arial.ttf"));
	off->setCharacterSize(30);
    off->setStyle(sf::Text::Bold);
	off->setColor(sf::Color::White);
	off-> setPosition(posx, posy);
	this->outSprite = off;

	this->posx = posx;
	this->posy = posy;

	this->callback = callback;

	activated = false;
}

MenuItem::~MenuItem() {
	delete this->onSprite;
	delete this->outSprite;
	cout << "Deleting menu item" << endl;
}

void MenuItem::enable() {
	this->activated = true;
}

void MenuItem::disable() {
	this->activated = false;
}

bool MenuItem::isEnabled() {
	return this->activated;
}

sf::Drawable * MenuItem::getDrawable() {
	if(this->activated)
		return this->onSprite;
	else 
		return this->outSprite;
}

void MenuItem::runCallback() {
	this->callback();
}