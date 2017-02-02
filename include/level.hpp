#ifndef PLATIPUS_LEVEL_HPP
#define PLATIPUS_LEVEL_HPP

#include "game_object.hpp"
#include "entity.hpp"
namespace platipus {
        class Level : public platipus::GameObject {
                public:
                        Level(platipus::entity::LEVEL_TYPE currLevel);
                        ~Level();
                        platipus::entity::LEVEL_TYPE id() const;
                        bool done() const;
                        void updateNextLevel(platipus::entity::LEVEL_TYPE nextLevel);
                        platipus::entity::LEVEL_TYPE nextLevel() const;
                        void finish();

                protected:
                        void loadLevel();

                private:
                        platipus::entity::LEVEL_TYPE mId;
                        platipus::entity::LEVEL_TYPE mNextLevel;
                        void handleEntityLoad(unsigned int entityType, std::ifstream* mapData);
                        bool mDone;
        };
}
#endif
