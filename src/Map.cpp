//
// Created by Даниил on 06.04.2022.
//

#include "Map.h"
#include "Settings.h"

Map::Map()
{

}

void Map::draw(sf::RenderTarget &window)
{
    sf::RectangleShape wall;
    wall.setSize({WINDOW_CELL_SIDE, WINDOW_CELL_SIDE});

    for(int i = 0; i < CELL_VERTICAL_COUNT; i++)
    {
        for(int j = 0; j < CELL_HORIZONTAL_COUNT; j++)
        {
            wall.setPosition({static_cast<float>(j*WINDOW_CELL_SIDE), static_cast<float>(i*WINDOW_CELL_SIDE)});

            switch (mapCell[i][j])
            {

                case WALL:
                    wall.setFillColor(sf::Color(150,150,150));
                    wall.setOutlineThickness(WINDOW_CELL_SIDE*5/45);
                    wall.setOutlineColor(sf::Color(150,150,170));
                    break;

                case VOID:
                    wall.setFillColor(sf::Color(200,200,200));
                break;
            }
            window.draw(wall);
        }
    }
}

Vector Map::loadMapFromImage(std::string imgPath)
{
    sf::Image mapImage;
    sf::Color pixel;

    Vector playerPosition;

    assert(mapImage.loadFromFile(imgPath));

    for(int i = 0; i < CELL_HORIZONTAL_COUNT; i++)
    {
        for(int j = 0; j < CELL_VERTICAL_COUNT; j++)
        {
            pixel = mapImage.getPixel(i,j);

            if(pixel == sf::Color(0,0,0))
            {
                mapCell[j][i] = WALL;
            }
            else if(pixel == sf::Color(255,0,0))
            {
                playerPosition = {static_cast<double>(i),static_cast<double>(j)};
                mapCell[j][i] = VOID;
            }
            else
            {
                mapCell[j][i] = VOID;
            }
        }
    }

    return playerPosition;
}

std::array<std::array<Entities, CELL_HORIZONTAL_COUNT>, CELL_VERTICAL_COUNT> &Map::getMapCell()
{
    return mapCell;
}
