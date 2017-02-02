#include "../include/level.hpp"
#include "../include/game.hpp"
#include "../include/transition_button.hpp"

#include <iostream>
#include <fstream>

namespace platipus {
        Level::Level(platipus::entity::LEVEL_TYPE currLevel) : GameObject(), mId(currLevel)
        {
                loadLevel();
        }

        Level::~Level()
        {
        }

        void
        Level::loadLevel()
        {
                std::string mapPath = "res/maps/" + std::to_string(mId);
                std::ifstream mapData(mapPath);

                unsigned int entityType;
                unsigned int next;

                if (mapData.is_open()) {
                        mapData >> std::hex >> next;
                        mNextLevel = platipus::entity::LEVEL_TYPE(next);
                        while (mapData >> std::hex >> entityType) {
                                handleEntityLoad(entityType, &mapData);
                        }
                }

                mapData.close();
        }

        void
        Level::handleEntityLoad(unsigned int entityType, std::ifstream* mapData)
        {
                switch (entityType) {
                        case platipus::entity::TRANSITION_BUTTON:
                                GameObject::addChild(new platipus::TransitionButton(mapData));
                                break;

                        default:
                                break;
                }
        }

        platipus::entity::LEVEL_TYPE
        Level::id() const
        {
                return mId;
        }

        bool
        Level::done() const
        {
                return mDone;
        }

        void
        Level::updateNextLevel(platipus::entity::LEVEL_TYPE next)
        {
                mNextLevel = next;
        }

        void
        Level::finish()
        {
                mDone = true;
        }

        platipus::entity::LEVEL_TYPE
        Level::nextLevel() const
        {
                return mNextLevel;
        }
}
