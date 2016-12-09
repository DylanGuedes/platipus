#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/window.hpp"

using Hash = std::map<std::string, std::string>;

int main()
{
        Hash options;
        options.emplace("VideoMode", "200 200");
        options.emplace("WindowName", "Platipus");

        platipus::Window window(options);

        while (window.listen()) {
                window.listenEvents();
        }

        return 0;
}
