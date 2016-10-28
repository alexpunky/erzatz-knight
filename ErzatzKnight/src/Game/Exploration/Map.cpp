#include "Map.h"
#include <cmath>
#include <iostream>

using namespace std;

using namespace ErzatzKnight;

Map::Map() {

}

Map::Map(Character * hero) {
    this->hero = hero;
}

Map::Map(int width, int height) {
    this->createRandomMap(width, height);
}

Map::Map(int width, int height, Character * character) { 
    this->hero = hero;
    this->createRandomMap(width, height);
}

Map::~Map() {
    delete this->cells;

    //list<NonPlayerCharacter *>::iterator it;
    //for(it = this->npcs->begin(); it != this->npcs->end(); it++) {
    //	delete *it;
    //}
    //delete this->npcs;
}

void Map::createRandomMap(int width, int height) {
    srand (time(NULL));
    this->width = width;
    this->height = height;
    Texture *rose = ResourceManager::getInstance()->getTexture("rose.bmp");
    Texture *vert = ResourceManager::getInstance()->getTexture("vert.bmp");
    Texture *bleu = ResourceManager::getInstance()->getTexture("bleu.bmp");

    int count = 0;
    this->cells = new Cell**[this->width];
    for(int i = 0; i<this->width; i++) {
        this->cells[i] = new Cell*[this->height];
        for(int j= 0; j<this->height; j++) {
            count++;
            Cell * cell = new Cell();
            int cell_val = rand() % 6;
            if(cell_val == 0) {
                cell->setOccupied(true);
                cell->setTexture(rose);
                cells[i][j] = cell;
            }
            else if(cell_val == 1) {
                cell->setTexture(vert);
                cells[i][j] = cell;
            }
            else {
                cell->setTexture(bleu);
                cells[i][j] = cell;
            }
        }
    }
}




/*void Map::addNonPlayerCharacter(NonPlayerCharacter * character) {
this->npcs->push_back(character);
}*/
