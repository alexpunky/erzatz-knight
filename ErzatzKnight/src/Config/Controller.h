#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>


namespace ErzatzKnight {
	class Controller {
		enum Analog {
			LeftX = 0,
			LeftY = 1,
			LTRT = 2,
			RightX = 4,
			RightY = 3,
			DigitalX = 6,
			DigitalY = 7
		};
		enum Buttons {
			A = 0,
			B = 1,
			X = 2,
			Y = 3,
			LB = 4,
			RB = 5,
			Start = 7,
			Back = 6,
			Home = 8,
			L3 = 9,
			R3 = 10,
		};

		static sf::Joystick::Axis toAxis(Controller::Analog stick);
	};
}

#endif