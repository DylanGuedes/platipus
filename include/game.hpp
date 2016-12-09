#ifndef PLATIPUS_GAME_HPP
#define PLATIPUS_GAME_HPP

#include "window.hpp"

namespace platipus {
        class Game {
                public:
                        Game();
                        ~Game();
                        void run();

                private:
                        Window *m_window;
                        Hash load_options();
        };
}

#endif
