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
                        void onEvent(sf::Event e);
                        virtual void handleMouseover(sf::Event e) = 0;
                        virtual void handleClick(sf::Event e) = 0;
                        virtual void handleClickOut(sf::Event e) = 0;

                private:
                        sf::Texture* mTexture;
                        sf::Texture* mTextureHighlight;
                        sf::Sprite* mSprite;
                        double mWidth = 0.0;
                        double mHeight = 0.0;
                        double mX = 0.0;
                        double mY = 0.0;
                        bool mTextureLoaded = false;
        };
}

#endif
