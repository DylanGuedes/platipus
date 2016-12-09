#ifndef PLATIPUS_GAME_OBJECT_HPP
#define PLATIPUS_GAME_OBJECT_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace platipus {
        class GameObject {
                public:
                        GameObject();
                        virtual ~GameObject();
                        void addChild(GameObject *child);
                        void update();
                        void draw(sf::RenderWindow *);
                        void handleEvent(sf::Event);

                protected:
                        virtual void updateSelf() {}
                        virtual void drawSelf(sf::RenderWindow *) {}
                        virtual void drawSelfAfter(sf::RenderWindow *) {}
                        virtual void onEvent(sf::Event) {}
                        std::vector<GameObject *> mChildren;

        };
}

#endif
