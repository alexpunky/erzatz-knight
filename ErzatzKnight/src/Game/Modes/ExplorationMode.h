#ifndef EXPLORATION_MODE_H
#define EXPLORATION_MODE_H

#include "Mode.h"
#include <Game/Characters/Character.h>
#include <Game/Exploration/Map.h>

using namespace ErzatzKnight;

namespace ErzatzKnight {
    namespace Modes {
        class ExplorationMode : public Mode {
        private:
            Character * hero;

            Map * map;
            int posx;
            int posy;
            int tile_size;
            int mid_tile_size;

            bool canMoveRight();
            bool canMoveLeft();
            bool canMoveUp();
            bool canMoveDown();

        public:
            ExplorationMode(Game& game, int width, int height);
            ~ExplorationMode();
            virtual void display();
            virtual void manageEvents();
            virtual void managePollEvent(sf::Event event);
            void changeSize(int width, int height);
        };
    }
}

#endif