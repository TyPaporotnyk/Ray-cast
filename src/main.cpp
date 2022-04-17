#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
    // Main entities
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    Player player;
    Map map;

    sf::Clock clock;

    // Load materials
    player.loadTexture(std::string(IMG_PATH)+"Player16.png");
    player.setPosition(map.loadMapFromImage(std::string(IMG_PATH)+"tileMap1.png"));

    while(window.isOpen())
    {
        // Control
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        // Control
        player.control(1, window, map);

        // Title builder
        auto textBuilder = std::ostringstream();

        textBuilder << std::setw(2) << 1'000'000 / clock.restart().asMicroseconds() << " FPS, ";
        textBuilder << std::setw(3) << player.getOrigin() << " origin, ";
        textBuilder << std::setprecision(2) << player.getDistance() << " distance";

        window.setTitle(textBuilder.str());

        // Draw
        map.draw(window);
        player.draw(window);

        window.display();
    }
    return 0;
}
