#include "Controller.h"

using namespace sf;
using namespace ErzatzKnight;

sf::Joystick::Axis Controller::toAxis(Controller::Analog stick) {
	switch(stick) {
		case Controller::LeftX:
		return sf::Joystick::X;
		case Controller::LeftY:
		return sf::Joystick::Y;
		case Controller::RightX:
		return sf::Joystick::U;
		case Controller::RightY:
		return sf::Joystick::V;
		case Controller::DigitalX:
		return sf::Joystick::PovX;
		case Controller::DigitalY:
		return sf::Joystick::PovY;
	}
}