#include "../include/game.hpp"
#include "../include/window.hpp"


namespace platipus {
        Game::Game()
        {
                Hash options = load_options();
                m_window = new platipus::Window(options);
        }

        Game::~Game()
        {
                delete m_window;
        }

        Hash
        Game::load_options()
        {
                // TODO
                Hash options;
                options.emplace("VideoMode", "200 200");
                options.emplace("WindowName", "Platipus");
                return options;
        }

        void
        Game::run()
        {
                while (m_window->listen()) {
                        m_window->listenEvents();
                }
        }
}
