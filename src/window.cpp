#include "../include/window.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace platipus {
        Window::Window(Hash options) :
                mOptions(options)
        {
                std::istringstream iss(options["VideoMode"]);
                unsigned int width, height;
                iss >> width >> height;
                mWindow = new sf::RenderWindow(sf::VideoMode(width, height), options["WindowName"]);
                mCurrentLevel = new platipus::Level("main-menu");
        }

        Window::~Window()
        {
                delete mWindow;
        }

        bool
        Window::listen() const
        {
                return mWindow->isOpen();
        }

        void
        Window::listenEvents()
        {
                sf::Event event;
                while (mWindow->pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                mWindow->close();
                }

                mWindow->clear(sf::Color::White);

                update();
                mCurrentLevel->update();
                draw(mWindow);
                mCurrentLevel->draw(mWindow);

                mWindow->display();
        }

        platipus::Level*
        Window::currentLevel() const
        {
                return mCurrentLevel;
        }

        void
        Window::updateSelf()
        {
        }
}
