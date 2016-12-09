#ifndef PLATIPUS_WINDOW_HPP
#define PLATIPUS_WINDOW_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

namespace platipus {
        using Hash = std::map<std::string, std::string>;
        class Window {
                public:
                        Window(std::map<std::string, std::string> options);
                        ~Window();
                        bool listen() const;
                        void listenEvents();

                protected:

                private:
                        sf::RenderWindow *m_window;
                        Hash m_options;
        };
}

#endif
