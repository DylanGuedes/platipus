#include "../include/window.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace platipus {
        Window::Window(Hash options) :
                m_options(options)
        {
                std::istringstream iss(options["VideoMode"]);
                unsigned int width, height;
                iss >> width >> height;
                m_window = new sf::RenderWindow(sf::VideoMode(width, height), options["WindowName"]);
        }

        Window::~Window()
        {
                delete m_window;
        }

        bool
        Window::listen() const
        {
                return m_window->isOpen();
        }

        void
        Window::listenEvents()
        {
                sf::Event event;
                while (m_window->pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                m_window->close();
                }

                m_window->clear();
                m_window->display();
        }
}
