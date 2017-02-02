#ifndef PLATIPUS_GAME_HPP
#define PLATIPUS_GAME_HPP

#include "window.hpp"
#include <SFML/Graphics.hpp>
#include <queue>

namespace platipus {
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
