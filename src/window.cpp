#include "../include/window.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/level.hpp"
#include "../include/entity.hpp"

namespace platipus {
        Window::Window(Hash options) :
                mOptions(options)
        {
                std::istringstream iss(options["VideoMode"]);
                unsigned int width, height;
                iss >> width >> height;
                mWindow = new sf::RenderWindow(sf::VideoMode(width, height), options["WindowName"]);
                mCurrentLevel = new platipus::Level(platipus::entity::LEVEL_TYPE::MAIN_MENU);
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
                        else  {
                                mCurrentLevel->handleEvent(event);
                        }
                }

                while (platipus::entity::pendingCommand()) {
                        std::cout << "NOT EMTPTY!!\n";
                        handleCommand();
                }

                mWindow->clear(sf::Color::White);

                update();
                if (not mCurrentLevel->done()) {
                        mCurrentLevel->update();
                        draw(mWindow);
                        mCurrentLevel->draw(mWindow);
                } else {
                        std::cout << "DONE!!\n";
                        platipus::entity::LEVEL_TYPE next = mCurrentLevel->nextLevel();
                        delete mCurrentLevel;
                        mCurrentLevel = new platipus::Level(next);
                }

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

        void
        Window::handleCommand()
        {
                int comm = platipus::entity::popCommand();
                switch (comm) {
                        case platipus::entity::COMMAND_TYPE::LEVEL_TRANSITION:
                                handleLevelTransition();
                                break;
                        default:
                                break;
                }
        }

        void
        Window::handleLevelTransition()
        {
                std::cout << "updated..\n";
                int nextLevel = platipus::entity::commandQueue->front();
                platipus::entity::commandQueue->pop();
                mCurrentLevel->updateNextLevel(platipus::entity::LEVEL_TYPE(nextLevel));
                std::cout << "updated..\n";
                mCurrentLevel->finish();
        }
}
