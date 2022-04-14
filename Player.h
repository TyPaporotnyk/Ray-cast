//
// Created by Даниил on 06.04.2022.
//

#ifndef STEP_PLAYER_H
#define STEP_PLAYER_H

#include "Vector.h"
#include <SFML/Graphics.hpp>
#include "Map.h"
#include <vector>

class Player
{
private:
    Vector position;

    float origin;
    float speed;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    float degToRad(int deg);
    float degCheck(int deg);

    bool collisionCheck(Vector position, Map& world);

public:

    float pDistance;
    Player(Vector position = {1,1}, float origin = 0, float speed = 0.08);

    void loadTexture(std::string texturePath);
    void draw(sf::RenderTarget& window);
    void control(float dTime, const sf::RenderWindow& window, Map& world);

    void setPosition(float x, float y);
    void setPosition(Vector position);
};


#endif //STEP_PLAYER_H
