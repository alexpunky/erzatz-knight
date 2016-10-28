#include "MenuMode.h"
#include <Resources/ResourceManager.h>
#include <Game/Game.h>
#include <unordered_set>
#include <vector>
#include <Config/Controller.h>


using namespace std;
using namespace ErzatzKnight::Modes;
using namespace ErzatzKnight;
using namespace sf;
using namespace std::placeholders;

MenuMode::MenuMode(Game& game, int width, int height) : Mode(game, width, height) {
    this->currentPosition = 0;
	this->menuItems.push_back(new MenuItem("Jouer", 400, 400, std::bind(&MenuMode::switchToExplorationMode, this)));
	this->menuItems.push_back(new MenuItem("Options", 400, 480, std::bind(&MenuMode::switchToExplorationMode, this)));
	this->menuItems.push_back(new MenuItem("Quitter", 400, 560, std::bind(&MenuMode::quit, this)));
	this->menuItems[this->currentPosition]->enable();
}

MenuMode::~MenuMode() {

}

void MenuMode::display() {
	vector<MenuItem *>::iterator it = this->menuItems.begin();
    while(it != this->menuItems.end()) {
		this->game->draw(*(*it)->getDrawable());
		it++;
	}
}

void MenuMode::manageEvents() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        sf::Sound * sound = ResourceManager::getInstance()->getSound("biggun3.wav");
        sound->setVolume(5);
        sound->play();
    }
}

void MenuMode::managePollEvent(sf::Event event) {
	switch(event.type) {
    case sf::Event::KeyPressed:
        switch(event.key.code) {
        case  sf::Keyboard::Escape:
            this->game->quit();
            break; 
        case sf::Keyboard::P:
            this->game->switchToExploration();
            break;
        case sf::Keyboard::Up:
            this->selectPrevious();
            break;
        case sf::Keyboard::Down:
            this->selectNext();
            break;
        case sf::Keyboard::Return:
			this->menuItems[this->currentPosition]->runCallback();
            break;
        }
        break;
	case sf::Event::JoystickButtonPressed:
		switch(event.joystickButton.button) {
		case sf::Joystick::PovX:
			cout << "POVX" << endl;
			break;
		case sf::Joystick::PovY:
			cout << "POVY" << endl;
			break;
		case sf::Joystick::R:
			cout << "R" << endl;
			break;
		case sf::Joystick::U:
			cout << "U" << endl;
			break;
		case sf::Joystick::V:
			cout << "V" << endl;
			break;
		case sf::Joystick::X:
			cout << "X" << endl;
				break;
		case sf::Joystick::Y:
			cout << "Y" << endl;
			break;
		case sf::Joystick::Z:
			cout << "Z" << endl;
			break;
		}
		break;
	case sf::Event::JoystickMoved:
		switch(event.joystickMove.axis) {
		case sf::Joystick::Axis::PovX:
			cout << "Axis POVX" << endl;
			break;
		case sf::Joystick::Axis::PovY:
			cout << "Axis POVY" << endl;
			break;
		case sf::Joystick::Axis::R:
			cout << "Axis R" << endl;
			break;
		case sf::Joystick::Axis::U:
			cout << "Axis U" << endl;
			break;
		case sf::Joystick::Axis::V:
			cout << "Axis V" << endl;
			break;
		case sf::Joystick::Axis::X:
			cout << "Axis X" << endl;
				break;
		case sf::Joystick::Axis::Y:
			cout << "Axis Y" << endl;
			break;
		case sf::Joystick::Axis::Z:
			cout << "Axis Z" << endl;
			break;

		}
		break;
    }
}

void MenuMode::selectPrevious() {
	this->menuItems[this->currentPosition]->disable();
	
	this->currentPosition--;
	int lg = this->menuItems.capacity();

	if(this->currentPosition < 0)
		this->currentPosition = (lg > 1) ? this->menuItems.capacity() - 1 : 0;

	this->menuItems[this->currentPosition]->enable();
}

void MenuMode::selectNext() {
	this->menuItems[this->currentPosition]->disable();
	
	this->currentPosition++;
	int lg = this->menuItems.capacity();

	if(this->currentPosition >= lg)
		this->currentPosition = 0;

	this->menuItems[this->currentPosition]->enable();
}

void MenuMode::switchToExplorationMode() {
	this->game->switchToExploration();
}

void MenuMode::quit() {
	this->game->quit();
}