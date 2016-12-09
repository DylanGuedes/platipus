#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/game.hpp"

using Hash = std::map<std::string, std::string>;

int main()
{
        platipus::Game game;

        game.run();

        return 0;
}
