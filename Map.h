//
// Created by Даниил on 06.04.2022.
//

#ifndef STEP_MAP_H
#define STEP_MAP_H

#include <SFML/Graphics.hpp>
#include <array>
#include "Settings.h"
#include "Vector.h"

enum Entities
{
    WALL,
    VOID
};

class Map
{
private:
    std::array<std::array<Entities, CELL_HORIZONTAL_COUNT>, CELL_VERTICAL_COUNT> mapCell;

public:
    Map();

    void draw(sf::RenderTarget& window);
    Vector loadMapFromImage(std::string imgPath);

    std::array<std::array<Entities, CELL_HORIZONTAL_COUNT>, CELL_VERTICAL_COUNT>& getMapCell();
};

#endif //STEP_MAP_H
