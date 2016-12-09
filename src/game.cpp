#include "../include/game.hpp"
#include "../include/window.hpp"


namespace platipus {
        Game::Game()
        {
                Hash options = loadOptions();
                mWindow = new platipus::Window(options);
        }

        Game::~Game()
        {
                delete mWindow;
        }

        Hash
        Game::loadOptions()
        {
                // TODO
                Hash options;
                options.emplace("VideoMode", "800 600");
                options.emplace("WindowName", "Platipus");
                return options;
        }

        void
        Game::run()
        {
                while (mWindow->listen()) {
                        mWindow->listenEvents();
                }
        }
}
