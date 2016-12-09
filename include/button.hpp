#ifndef PLATIPUS_BUTTON_HPP
#define PLATIPUS_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "game_object.hpp"

namespace platipus {
        class Button : public platipus::GameObject {
                public:
                        Button(std::ifstream* mapData);
                        ~Button();

                protected:
                        sf::Texture *texture() const;
                        void loadTexture(std::ifstream* mapData);
                        void loadPosition(std::ifstream* mapData);
                        void drawSelf(sf::RenderWindow *canvas);

                private:
                        sf::Texture* mTexture;
                        sf::Sprite* mSprite;
                        void setTexture(std::string name);
                        unsigned int mWidth = 0;
                        unsigned int mHeight = 0;
                        bool mTextureLoaded = false;
        };
}

#endif
