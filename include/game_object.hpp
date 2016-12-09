#ifndef PLATIPUS_GAME_OBJECT_HPP
#define PLATIPUS_GAME_OBJECT_HPP

#include <vector>
#include <SFML/Graphics.hpp>

namespace platipus {
        class GameObject {
                public:
                        GameObject(GameObject *parent=nullptr);
                        virtual ~GameObject();

                        void addChild(GameObject *child) {
                                mChildren.push_back(child);
                        }

                protected:
                        virtual void updateSelf() {
                                for (auto it : mChildren) {
                                        it->updateSelf();
                                }
                        }

                        virtual void drawSelf(sf::RenderWindow *canvas) {
                                for (auto it : mChildren) {
                                        it->drawSelf(canvas);
                                }
                        }

                        virtual void drawSelfAfter(sf::RenderWindow *canvas) {
                                for (auto it : mChildren) {
                                        it->drawSelfAfter(canvas);
                                }
                        }

                private:
                        GameObject *mParent;
                        std::vector<GameObject *> mChildren;

        };
}

#endif
