#ifndef MODE_H
#define MODE_H

#include <SFML/Window.hpp>

namespace ErzatzKnight {
	class Game; 

    namespace Modes {
        class Mode {
        private:
            bool active;


        public:
            //static sf::Input input;
            Game * const game;
            int width;
            int height;
            float ratio;
            virtual void manageEvents() = 0;
            virtual void managePollEvent(sf::Event event) = 0;
            virtual void display() = 0;
            inline Mode(Game& game, int width, int height): game(&game) { 
                this->changeSize(width, height);
            }

            inline void changeSize(int width, int height) {
                this->width = width; 
                this->height= height; 
                this->ratio = ((float)this->width/600.0f); 
            }
        };
    }
}

#endif