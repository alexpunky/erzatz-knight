#include "Cell.h"

using namespace ErzatzKnight;

Cell::Cell() {

}


Cell::Cell(Texture * texture) {
    this->texture = texture;
    this->isOccupied = false;
}

Cell::Cell(Texture * texture, bool occupied) {
    this->texture = texture;
    this->isOccupied = occupied;
}

Cell::~Cell() {

}

Texture * Cell::getTexture() {
    return this->texture;
}

void Cell::setTexture(Texture * texture) {
    this->texture = texture;
}

void Cell::setOccupied(bool occupied) {
    this->isOccupied = occupied;
}