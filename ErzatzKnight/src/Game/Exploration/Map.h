#ifndef MAP_H
#define MAP_H

#include "Cell.h"
#include <Resources/ResourceManager.h>
#include <Config/Types.h>
#include <Game/Characters/Character.h>
#include <list>

using namespace std;
using namespace ErzatzKnight;

namespace ErzatzKnight {
    class Map {
    private:
        int width;
        int height;
        Cell *** cells;
        Character * hero;

        void createRandomMap(int width, int height);

        //list<NonPlayerCharacter *> * npcs;
    public:
        Map();
        Map(Character * hero);
        Map(int width, int height);
        Map(int width, int height, Character * hero);
        ~Map();

        //GETTERS
        inline int getWidth() { return this->width; }
        inline int getHeight() { return this->height; }

        void addCells(Cell * cell);
        inline Cell* getCell(int x, int y) {
            return this->cells[x][y];
        }

        //void addNonPlayerCharacter(NonPlayerCharacter * character);
    };
}

#endif;