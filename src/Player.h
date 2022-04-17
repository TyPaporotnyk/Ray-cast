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

    double origin;
    double speed;
    double distance;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    double degToRad(int deg);
    double degCheck(int deg);

    bool collisionCheck(Vector position, Map& world);

public:


    explicit Player(Vector position = {1,1}, double origin = 0, double speed = 0.08, double pDistance = 0);

    void loadTexture(std::string texturePath);
    void draw(sf::RenderTarget& window);
    void control(double dTime, const sf::RenderWindow& window, Map& world);

    void setPosition(Vector position);

    double getDistance() const;

    double getOrigin() const;
};


#endif //STEP_PLAYER_H
