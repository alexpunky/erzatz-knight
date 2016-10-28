#ifndef MENUITEM_H
#define MENUITEM_H

#include <SFML/Graphics/Drawable.hpp>
#include <string>
#include <functional>

using namespace sf;
using namespace std;

namespace ErzatzKnight {
	namespace Menus {
		class MenuItem {

		private:
			bool activated;
			sf::Drawable *onSprite;
			sf::Drawable *outSprite;
			int posx;
			int posy;
			std::function<void(void)> callback;

		public:
			MenuItem(string value, int posx, int posy, std::function<void(void)> callback);
			~MenuItem();

			void enable();
			void disable();
			void runCallback();

			bool isEnabled();

			sf::Drawable * getDrawable();
		};
	}
}

#endif