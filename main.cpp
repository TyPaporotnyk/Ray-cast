#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "Player.h"
#include "Map.h"
#include "Time.h"
#include "cmath"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "FPS");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    Player player;
    Map map;

    player.loadTexture("img/Player16.png");
    player.setPosition(map.loadMapFromImage("img/tileMap1.png"));

    while(window.isOpen())
    {
        Time::update();
        float dTime = Time::deltaTime();

        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        player.control(1, window, map);

        std::string title = std::to_string((int)round(1.0 / dTime)) + " FPS, " + std::to_string((int)player.pDistance)
                +" metres";

        window.setTitle(title);

        map.draw(window);
        player.draw(window);

        window.display();
    }
    return 0;
}
