//
// Created by Даниил on 06.04.2022.
//

#include "Player.h"
#include "Settings.h"
#include <cmath>
#include <iostream>

Player::Player(Vector position, double origin, double speed, double distance) :
position(position), origin(origin), speed(speed), distance(distance)
{

}

bool Player::collisionCheck(Vector position ,Map &world)
{
    double cellX = position.x;
    double cellY = position.y;

    for(int i = 0; i < 4; i++)
    {
        int x;
        int y;

        switch (i)
        {
            case 0:
                x = floor(cellX);
                y = floor(cellY);
                break;

            case 1:
                x = ceil(cellX);
                y = ceil(cellY);
                break;

            case 2:
                x = ceil(cellX);
                y = floor(cellY);
                break;

            case 3:
                x = floor(cellX);
                y = ceil(cellY);
                break;
        }

        if((x >= 0 && y >= 0) && (x <= CELL_HORIZONTAL_COUNT*WINDOW_CELL_SIDE && y <= CELL_VERTICAL_COUNT*WINDOW_CELL_SIDE))
        {
            if(world.getMapCell()[y][x] == Entities::WALL)
            {
                return true;
            }
        }
    }

    return false;
}

void Player::loadTexture(std::string texturePath)
{
    assert(playerTexture.loadFromFile(texturePath));
    playerSprite.setTexture(playerTexture);
}

void Player::draw(sf::RenderTarget &window)
{
    double rec = floor(degCheck(origin+9)/(360.0/31.0))+1;

    playerSprite.setPosition(position.x*WINDOW_CELL_SIDE, position.y*WINDOW_CELL_SIDE);
    playerSprite.setTextureRect(sf::IntRect((rec*16)-16,0,16,16));
    playerSprite.setScale(WINDOW_CELL_SIDE/16,WINDOW_CELL_SIDE/16);

    sf::CircleShape circleShape (8);
    circleShape.setPosition((position.x * WINDOW_CELL_SIDE) + cos(degToRad(origin)) * distance * WINDOW_CELL_SIDE + 4,
                            (position.y * WINDOW_CELL_SIDE) - sin(degToRad(origin)) * distance * WINDOW_CELL_SIDE + 4);

    window.draw(circleShape);
    window.draw(playerSprite);
}

void Player::control(double dTime, const sf::RenderWindow& window, Map& world)
{
    double dX = 0;
    double dY = 0;

    double windowCenterX = round(window.getSize().x / 2);
    double windowCenterY = round(window.getSize().y / 2);

    double rotationHorizontal = round(90 * (windowCenterX - sf::Mouse::getPosition(window).x) / window.getSize().x);

    origin = degCheck(origin + rotationHorizontal);

    sf::Mouse::setPosition(sf::Vector2i(windowCenterX, windowCenterY), window);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dX = speed * cosf(degToRad(degCheck(origin + 90))) * dTime;
        dY = -speed * sinf(degToRad(degCheck(origin + 90))) * dTime;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dX = speed * cosf(degToRad(degCheck(origin - 90))) * dTime;
        dY = -speed * sinf(degToRad(degCheck(origin - 90))) * dTime;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dX += speed * cosf(degToRad(origin)) * dTime;
        dY -= speed * sinf(degToRad(origin)) * dTime;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dX -= speed * cosf(degToRad(origin));
        dY += speed * sinf(degToRad(origin));
    }

    if(!collisionCheck({position.x+dX, position.y+dY}, world))
    {
        position.x += dX;
        position.y += dY;
    }
    else if(!collisionCheck({position.x+dX, position.y}, world))
    {
        position.x += dX;
        position.y = round(position.y);
    }
    else if(!collisionCheck({position.x, position.y+dY}, world))
    {
        position.x = round(position.x);
        position.y += dY;
    }
    else
    {
        position.x = round(position.x);
        position.y = round(position.y);
    }

    Vector rayDirection = {cos(degToRad(origin)), -sin(degToRad(origin))};
    rayDirection.normalize();
    Vector rayStart = position;
    Vector rayUnitStepSize = {static_cast<double >(sqrt(1 + (rayDirection.y / rayDirection.x)*(rayDirection.y /
                          rayDirection
                          .x))),
                              static_cast<double >(sqrt(1 + (rayDirection.x / rayDirection.y)*(rayDirection.x /
                          rayDirection.y)))};

    Vector mapCheck = rayStart + 0.5f;
    Vector rayLength1D;
    Vector step;

    if (rayDirection.x < 0)
    {
        step.x = -1;
        rayLength1D.x = (rayStart.x - double (mapCheck.x - 1)) * rayUnitStepSize.x;
    } else
    {
        step.x = 1;
        rayLength1D.x = (double (mapCheck.x) - rayStart.x) * rayUnitStepSize.x;
    }

    if (rayDirection.y < 0)
    {
        step.y = -1;
        rayLength1D.y = (rayStart.y - double (mapCheck.y - 1)) * rayUnitStepSize.y;
    } else
    {
        step.y = 1;
        rayLength1D.y = (double (mapCheck.y) - rayStart.y) * rayUnitStepSize.y;
    }

    double maxDistance = 15;
    double tdistance = 0;
    while (distance <= maxDistance)
    {
        if (rayLength1D.x < rayLength1D.y)
        {
            mapCheck.x += step.x;
            tdistance = rayLength1D.x;
            rayLength1D.x += rayUnitStepSize.x;
        } else
        {
            mapCheck.y += step.y;
            tdistance = rayLength1D.y;
            rayLength1D.y += rayUnitStepSize.y;
        }

        if (mapCheck.x >= 0 && mapCheck.x < CELL_HORIZONTAL_COUNT &&
            mapCheck.y >= 0 && mapCheck.y < CELL_VERTICAL_COUNT)
        {
            if (world.getMapCell()[(int)mapCheck.y][(int)mapCheck.x] == WALL)
            {
                break;
            }
        }
    }

    distance = std::min(tdistance, maxDistance);
}

double Player::degToRad(int deg)
{
    return deg*M_PI/180;
}

double Player::degCheck(int deg)
{
    return (360 + (deg % 360))% 360;
}

void Player::setPosition(Vector position)
{
    this->position = position;
}

double Player::getDistance() const
{
    return distance;
}

double Player::getOrigin() const
{
    return origin;
}
