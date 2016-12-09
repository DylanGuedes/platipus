#include "../include/game_object.hpp"

namespace platipus {
        GameObject::GameObject()
        {
        }

        GameObject::~GameObject()
        {
                for (auto &item : mChildren) {
                        delete item;
                }
        }

        void
        GameObject::update()
        {
                updateSelf();
                for (auto it : mChildren) {
                        it->updateSelf();
                }
        }

        void
        GameObject::draw(sf::RenderWindow *canvas)
        {
                drawSelf(canvas);
                for (auto it : mChildren) {
                        it->draw(canvas);
                }
                drawSelfAfter(canvas);
        }

        void
        GameObject::addChild(GameObject *child)
        {
                mChildren.push_back(child);
        }

        void
        GameObject::handleEvent(sf::Event e)
        {
                onEvent(e);
                for (auto it : mChildren) {
                        it->handleEvent(e);
                }
        }
}
