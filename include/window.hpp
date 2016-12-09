#ifndef PLATIPUS_WINDOW_HPP
#define PLATIPUS_WINDOW_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "../include/game_object.hpp"
#include "level.hpp"

namespace platipus {
        using Hash = std::map<std::string, std::string>;
        class Window : public platipus::GameObject {
                public:
                        Window(std::map<std::string, std::string> options);
                        ~Window();
                        bool listen() const;
                        void listenEvents();

                protected:
                        void updateSelf();
                        platipus::Level *currentLevel() const;

                private:
                        sf::RenderWindow *mWindow;
                        Hash mOptions;
                        platipus::Level *mCurrentLevel = nullptr;
        };
}

#endif
