#ifndef PLATIPUS_GAME_HPP
#define PLATIPUS_GAME_HPP

#include "window.hpp"
#include <SFML/Graphics.hpp>

namespace platipus {
        namespace entity {
                const unsigned int BUTTON = 0xFF0;
        }
        class Game {
                public:
                        Game();
                        ~Game();
                        void run();

                protected:

                private:
                        Window *mWindow;
                        Hash loadOptions();
        };
}

#endif
