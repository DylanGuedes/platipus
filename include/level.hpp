#ifndef PLATIPUS_LEVEL_HPP
#define PLATIPUS_LEVEL_HPP

#include "game_object.hpp"
namespace platipus {
        class Level : platipus::GameObject {
                public:
                        Level(std::string id);
                        ~Level();
                        std::string id() const;

                protected:
                        void loadLevel();

                private:
                        std::string mId;
                        void handleEntityLoad(unsigned int entityType, std::ifstream& mapData);
        };
}
#endif
