#include "../include/level.hpp"
#include "../include/game.hpp"

#include <iostream>
#include <fstream>

namespace platipus {
        Level::Level(std::string id) :
                mId(id)
        {
                loadLevel();
        }

        Level::~Level()
        {
        }

        void
        Level::loadLevel()
        {
                std::cout << "loading level..\n";
                std::string mapPath = "res/maps/" + id();
                std::ifstream mapData(mapPath);
                unsigned int entityType;

                if (mapData.is_open()) {
                        while (mapData >> entityType) {
                                handleEntityLoad(entityType, mapData);
                        }
                }

                mapData.close();
        }

        void
        Level::handleEntityLoad(unsigned int entityType, std::ifstream& mapData)
        {
                switch (entityType) {
                        case platipus::entity::BUTTON:
                                // addChild(new platipus::Button(mapData));
                                break;

                        default:
                                break;

                }
        }

        std::string
        Level::id() const
        {
                return mId;
        }
}
