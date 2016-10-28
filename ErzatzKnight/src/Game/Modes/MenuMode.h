#ifndef MENUMODE_H
#define MENUMODE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Sound/SoundEngine.h>
#include "Mode.h"
#include <Menu/MenuItem.h>

using namespace std;
using namespace ErzatzKnight::Menus;

namespace ErzatzKnight {
    namespace Modes {
        class MenuMode : public Mode {

        private:
            int currentPosition;
			vector<MenuItem *> menuItems;
            static const int MENU_PLAY = 0;
            static const int MENU_OPTION = 1;
            static const int MENU_EXIT = 2;

        public:
            MenuMode(Game& game, int width, int height);
            ~MenuMode();
            virtual void display();
            virtual void manageEvents();
            virtual void managePollEvent(sf::Event event);

			void selectPrevious();
			void selectNext();

			void switchToExplorationMode();
			void quit();
        };
    }
}

#endif