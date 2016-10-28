#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

using namespace sf;

namespace ErzatzKnight {
    class Cell {
    private:
        bool isOccupied;
        Texture * texture;

    public:
        Cell();
        Cell(Texture * texture);
        Cell(Texture * texture, bool occupied);
        ~Cell();

        Texture * getTexture();
        void setTexture(Texture * texture);
        void setOccupied(bool occupied);
    };
}

#endif